#include "ae.h"
#include <math.h>
#include <time.h>

using namespace std;

// initialisation des paramétres de l'AG et génération de la population initiale
Ae::Ae(int tp, double tcroisement, double tmutation, int tc)
{
	taille_pop        = tp;
	taux_croisement   = tcroisement;
	taux_mutation     = tmutation;
	taille_chromosome = tc;
	pop   = new population(taille_pop, taille_chromosome);
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
	pop->statistiques();

	unsigned long time_limit = 1 * 60 * 1000; //temps limite en millisecondes
	unsigned long time = 0; //temps courant en millisecondes
	clock_t time_start = clock(); //temps au début en ticks d'horloge
	int g = 0;

	//tant que la limite de temps n'est pas atteinte, à savoir 15min
	while(time < time_limit)
	{
		//sélection de deux individus de la population courante
		pere = pop->selection_tournoi();
		mere = pop->selection_tournoi();
		bool stop_temps = false;

		// On effectue un croisementavec une probabilité "taux_croisement"
		if(Random::aleatoire(1000)/1000.0 < taux_croisement)
		{
			bool solution_valide = false;
			while(!solution_valide && !stop_temps) {
				croisementDoubleNX(pere, mere, enfant1, enfant2);
				enfant1->majTempsTravailInterface();
				enfant2->majTempsTravailInterface();
				if(enfant1->valide() && enfant2->valide()) {
					solution_valide = true;
				}
				time = (clock() - time_start) * 1000 / CLOCKS_PER_SEC;
				if(time > time_limit) {
					stop_temps = true;
				}
			}
		}
		else
		{
			enfant1->copier(pere);
			enfant2->copier(mere);
			enfant1->majTempsTravailInterface();
			enfant2->majTempsTravailInterface();
		}

		// On effectue la mutation d'un enfant avec une probabilité "taux_mutation"
		if(Random::aleatoire(1000)/1000.0 < taux_mutation) {
			bool solution_valide = false;
			while(!solution_valide && !stop_temps) {
				enfant1->melange_alea_genes();
				enfant1->majTempsTravailInterface();
				solution_valide = enfant1->valide();
				time = (clock() - time_start) * 1000 / CLOCKS_PER_SEC;
				if(time > time_limit) {
					stop_temps = true;
				}
			}
		}

		// On effectue la mutation de l'autre enfant avec une probabilité "taux_mutation"
		if(Random::aleatoire(1000)/1000.0 < taux_mutation) {
			bool solution_valide = false;
			while(!solution_valide && !stop_temps) {
				enfant2->melange_alea_genes();
				enfant2->majTempsTravailInterface();
				solution_valide = enfant2->valide();
				time = (clock() - time_start) * 1000 / CLOCKS_PER_SEC;
				if(time > time_limit) {
					stop_temps = true;
				}
			}
		}

		if(!stop_temps) {
			// �valuation des deux nouveaux individus g�n�r�s
			enfant1->evaluer();
			enfant2->evaluer();

			// Insertion des nouveaux individus dans la population
			pop->remplacement_tournoi(enfant1);
			pop->remplacement_tournoi(enfant2);

			// On réordonne la population selon la fitness
			pop->reordonner();

			// Si l'un des nouveaux indivudus-solutions est le meilleur jamais renconté
			if (pop->individus[pop->ordre[0]]->fitness < best_fitness)
			{
				best_fitness = pop->individus[pop->ordre[0]]->fitness;
				cout << "Amelioration de la meilleure solution a la generation " << g << " : " << best_fitness << endl;
				amelioration = g;
			}

			g++;
			time = (clock() - time_start) * 1000 / CLOCKS_PER_SEC;
		}

	}
	//  on affiche les statistiques de la population finale
	cout << "Quelques statistiques sur la population finale" << endl;
	pop->statistiques();

	//retourner le meilleur individu rencontré pendant la recherche
	return pop->individus[pop->ordre[0]];
}

void Ae::sort(int* tab, int size) {
	for(int i = 0; i < size; i++) {
		int min = tab[i];
    	int indice = i;
		for(int j = i+1; j < size; j++) {
			if(tab[j] < min) {
				min = tab[j];
        		indice = j;
			}
		}
    	tab[indice] = tab[i];
		tab[i] = min;
	}
}

bool Ae::isInArray(int value, int* tab, int size) {
	bool res = false;
	for(int i = 0; i < size; i++) {
		if(tab[i] == value) {
			res = true;
		}
	}
	return res;
}

void Ae::croisementDoubleNX(chromosome* parent1, chromosome* parent2,
												chromosome* enfant1, chromosome* enfant2)
{
	int premierCroisementN = Random::aleatoire_min_max(1, 5);

	chromosome* enfant_intermediaire1 = new chromosome(parent1->taille);
	chromosome* enfant_intermediaire2 = new chromosome(parent1->taille);

	croisementNX(parent1, parent2, enfant1, enfant2, premierCroisementN);
	enfant_intermediaire1->copier(enfant1);
	enfant_intermediaire2->copier(enfant2);

	int deuxiemeCroisementN = Random::aleatoire_min_max(1, 5);
	while(deuxiemeCroisementN == premierCroisementN) {
		deuxiemeCroisementN = Random::aleatoire_min_max(1, 5);
	}

	croisementNX(enfant_intermediaire1, enfant_intermediaire2, enfant1, enfant2, deuxiemeCroisementN);

	delete enfant_intermediaire1;
	delete enfant_intermediaire2;

}

void Ae::croisementNX(chromosome* parent1, chromosome* parent2,
												chromosome* enfant1, chromosome* enfant2, int croisementN)
{
	int nb_genes = parent1->taille;
	bool regular_add = true;
	int* points_croisements = new int[croisementN+1];

	for(int i = 0; i < croisementN; i++) {
		int alea = Random::aleatoire(nb_genes);
		while(isInArray(alea, points_croisements, i) == true) {
			alea = Random::aleatoire(nb_genes);
		}
		points_croisements[i] = alea;
	}
	points_croisements[croisementN] = nb_genes;
	sort(points_croisements, croisementN);

	int start = 0;
	for(int i = 0; i < croisementN+1; i++) {
		int croisement = points_croisements[i];
		if(regular_add == true) {
			for(int j = start; j < croisement; j++) {
				enfant1->genes[j] = parent1->genes[j];
				enfant2->genes[j] = parent2->genes[j];
			}
			regular_add = false;
		}
		else {
			for(int j = start; j < croisement; j++) {
				enfant1->genes[j] = parent2->genes[j];
				enfant2->genes[j] = parent1->genes[j];
			}
			regular_add = true;
		}
		start = croisement;
	}

	delete[] points_croisements;
}
