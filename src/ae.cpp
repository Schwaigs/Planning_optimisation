#include "ae.h"
#include <math.h>

using namespace std;

// initialisation des paramétres de l'AG et génération de la population initiale
Ae::Ae(int nbg, int tp, double tcroisement, double tmutation, int tc)
{
	nbgenerations     = nbg;
	taille_pop        = tp;
	taux_croisement   = tcroisement;
	taux_mutation     = tmutation;
	taille_chromosome = tc;
	test_acces_donnees_instances();
    
	pop   = new population(taille_pop, taille_chromosome);
    
    pop->individus[0]->evaluer();
}

// destructeur de l'objet Ae
Ae::~Ae()
{
	delete pop;
}

// procédure principale de la recherche
chromosome* Ae::optimiser()
{
	int amelioration = 0;
	chromosome *enfant1 = new chromosome(taille_chromosome);
	chromosome *enfant2 = new chromosome(taille_chromosome);
	chromosome *pere;
	chromosome *mere;
	int best_fitness;
	// évaluation des individus de la population initiale
	for(int ind=0; ind<taille_pop; ind++)
		pop->individus[ind]->evaluer();

	// on ordonne les indivudus selon leur fitness
	pop->ordonner();

	best_fitness = pop->individus[pop->ordre[0]]->fitness;
	//  on affiche les statistiques de la population initiale
	cout << "Quelques statistiques sur la population initiale" << endl;
	pop->statiatiques();

	//tant que le nombre de générations limite n'est pas atteint
	for(int g=0; g<nbgenerations; g++)
	{
		//sélection de deux individus de la population courante
		pere = pop->selection_tournoi();
		mere = pop->selection_tournoi();

		// On effectue un croisementavec une probabilité "taux_croisement"
		if(Random::aleatoire(1000)/1000.0 < taux_croisement)
		{
			//croisement1X(pere, mere, enfant1, enfant2);
		}
		else
		{
			enfant1->copier(pere);
			enfant2->copier(mere);
		}

		// On effectue la mutation d'un enfant avec une probabilité "taux_mutation"
		if(Random::aleatoire(1000)/1000.0 < taux_mutation)
			enfant1->echange_2_genes_consecutifs();

		// On effectue la mutation de l'autre enfant avec une probabilité "taux_mutation"
		if(Random::aleatoire(1000)/1000.0 < taux_mutation)
			enfant2->echange_2_genes_consecutifs();

		// �valuation des deux nouveaux individus g�n�r�s
		enfant1->evaluer();
		enfant2->evaluer();

		// Insertion des nouveaux individus dans la population
        
		pop->remplacement_tournoi(enfant1);
		pop->remplacement_tournoi(enfant2);
        /*
        for (int i = 0; i < taille_pop-1; i++){
            if (pop->individus[i]==pere)
            {
                pop->individus[i]==enfant1;
            }else if(pop->individus[i]==mere){
                pop->individus[i]==enfant2;
            }
            
        }*/

		// On réordonne la population selon la fitness
		pop->reordonner();

		// Si l'un des nouveaux indivudus-solutions est le meilleur jamais renconté
		if (pop->individus[pop->ordre[0]]->fitness < best_fitness)
		{
			best_fitness = pop->individus[pop->ordre[0]]->fitness;
			cout << "Amelioration de la meilleure solution a la generation " << g << " : " << best_fitness << endl;
			amelioration = g;
		}
	}
	//  on affiche les statistiques de la population finale
	cout << "Quelques statistiques sur la population finale" << endl;
	pop->statiatiques();
	//  on affiche la consanginité de la population finale
	pop->similitude();

	//retourner le meilleur individu rencontré pendant la recherche
	return pop->individus[pop->ordre[0]];
}

// opérateur de croisement é un point : croisement 1X
// 1) l'opérateur 1X choisit de maniére aléatoire un point de croisement
// 2) l'opérateur 1X recopie le début du parent 1 au début de l'enfant 1
//                     et le début du parent 2 au début de l'enfant 2.
// 3) l'opérateur 1X compléte l'enfant 1 avec les génes manquant en les plaéant dans l'ordre du parent 2
//                         et l'enfant 2 avec les génes manquant en les plaéant dans l'ordre du parent 1.
//    Le 1ier enfant est le produit de la partie haute du premier parent et
//    de la partie basse du deuxiéme parent et inversement pour le 2éme enfant
void Ae::croisement1X(chromosome* parent1, chromosome* parent2,
                      chromosome* enfant1, chromosome* enfant2)
{
	int nb_genes = parent1->taille;

	int* odre_parent1 = new int[nb_genes];
	int* odre_parent2 = new int[nb_genes];

	for (int i=0; i<nb_genes; i++)
	{
		odre_parent1[parent1->genes[i]] = i;
		odre_parent2[parent2->genes[i]] = i;
	}

	// 1) l'opérateur 1X choisit de maniére aléatoire le point de croisement
	int point = Random::aleatoire(nb_genes);

	// 2) l'opérateur 1X recopie le début du parent 1 au début de l'enfant 1
	//                     et le début du parent 2 au début de l'enfant 2.
	enfant1->copier(parent1);
	enfant2->copier(parent2);

	// 3) l'opérateur 1X compléte l'enfant 1 avec les génes manquant en les plaéant dans l'ordre du parent 2
	//                         et l'enfant 2 avec les génes manquant en les plaéant dans l'ordre du parent 1.
	for (int k=point+1; k<nb_genes; k++)
	{
		for (int l=k+1; l<nb_genes; l++)
		{
			if(odre_parent2[enfant1->genes[k]]>odre_parent2[enfant1->genes[l]])
				enfant1->echange_2_genes(k,l);
			if(odre_parent1[enfant2->genes[k]]>odre_parent1[enfant2->genes[l]])
				enfant2->echange_2_genes(k,l);
		}
	}
	delete[] odre_parent1;
	delete[] odre_parent2;
}

// opérateur de croisement é deux points : croisement 2X
// 1) l'opérateur 2X choisit de maniére aléatoire 2 points de croisement
// 2) l'opérateur 2X recopie le début du parent 1 au début de l'enfant 1
//                        et le début du parent 2 au début de l'enfant 2.
// 3) l'opérateur 2X compléte l'enfant 1 avec les génes manquant en les plaéant dans l'ordre du parent 2
//                         et l'enfant 2 avec les génes manquant en les plaéant dans l'ordre du parent 1.
void Ae::croisement2X(chromosome* parent1, chromosome* parent2,
                      chromosome* enfant_s1, chromosome* enfant_s2)
{
}

void Ae::croisement2LOX(chromosome* parent1, chromosome* parent2,
                        chromosome* enfant_s1, chromosome* enfant_s2)
{
}

void Ae::test_acces_donnees_instances()
{	
	int idApprenant = 5;
	int idIntervenant = 6;
	int idCours = 0;

	int specialiteApprenant = formation[idApprenant][idCours][1];
	cout << "Specialite apprenant = " << specialiteApprenant << endl;
	bool checkSpecialiteIntervenant = specialite_interfaces[idIntervenant][specialiteApprenant];
	cout << "L'intervenant possede la bonne Spécialité = " << checkSpecialiteIntervenant << endl;

	int distance = abs(sqrt(pow(coord[specialiteApprenant+1][0] - coord[0][0],2) + pow(coord[specialiteApprenant+1][1] - coord[0][1],2)));
	cout << "Coordonées SESSAD = [" << coord[0][0] << "," << coord[0][1] << "]" << endl;
	cout << "Coordonées du centre de formation de l'apprenant = [" << coord[specialiteApprenant+1][0] << "," << coord[specialiteApprenant+1][1] << "]" << endl;
	cout << "Distance entre les deux centres = " << distance << endl;
    
}

