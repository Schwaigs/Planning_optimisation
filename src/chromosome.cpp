#include <list>
#include "chromosome.h"

using namespace std;

// initialisation des param�tres d'un chromosome
chromosome::chromosome(int tc)
{
	//au depart chacune des interface est encore plainement disponible, elle a donc 35h restantes
	tempsRestantIntervenants =  new int[NBR_INTERFACES];
	for(int i=0; i<NBR_INTERFACES; i++){
		tempsRestantIntervenants[i] = 35;
	}

	taille = tc;
	// un chromosome est compos� de 'taille' g�nes,
	// les g�nes sont carat�ris� par un entier compris entre 0 et 'taille-1'
	genes = new int[taille];
	//initialisation a -1 partout car 0 est une valeur valide qu'il faut différencier
	for(int i=0; i<taille; i++){
		genes[i] = -1;
	}

	//on parcourt la liste des apprenants pour leur attribuer à chacun une interface
	for(int i=0; i<taille; i++){
		
		//on stocke les interfaces possedants la bonne competence
		int competenceApprenant = formation[i][2];
		list<int> interfaceMatch;

		for(int j=0; j<NBR_INTERFACES; j++){
			bool checkCompetenceIntervenant = competences_interfaces[j][competenceApprenant];
			if(checkCompetenceIntervenant){
				interfaceMatch.push_back(j);
			}
		}

		//on verifie que ces interfaces sont bien disponibles pour ce creneau de formation
		for(list<int>::iterator it = interfaceMatch.begin(); it != interfaceMatch.end(); it++){
			int idIntervenant = *it;
			bool dispo = interfaceDispo(idIntervenant, i);

			//si l'interface est toujours disponible, on verifie qu'elle ne depassera pas les 35h en lui ajoutant le creneau courant
			if(dispo){
				if( (tempsRestantIntervenants[idIntervenant] - (formation[i][5]-formation[i][4])) < 0){
					dispo = false;
				}
			}

			//si l'interface n'est pas disponible on la retire de la liste
			if(!dispo){
				it = interfaceMatch.erase(it);
				--it;
			}

		}

		//on choisi enfin aléatoirement l'interface qui sera affectée pour le creneau parmis celles disponibles
		int a = Random::aleatoire(interfaceMatch.size());

		//on parcours la liste des interfaces disponibles
		list<int>::iterator it = interfaceMatch.begin();
		for (int j=0; j<a; j++){
			it++;
		}
		genes[i] = *it;

		//on met à jour son nombre d'heure restant
		tempsRestantIntervenants[genes[i]] -= formation[i][5]-formation[i][4];
	}
}

// destruction de l'objet 'chromosome'
chromosome::~chromosome()
{
	delete genes;
}

//vérifie la disponibilité d'une interface pour un creaneau de formation
bool chromosome::interfaceDispo(int idIntervenant, int idFormation){
	bool dispo = true; 

	int centreCreneauCourant = formation[idFormation][1];
	int jCreneauCourant = formation[idFormation][3];
	int hDebutCreneauCourant = formation[idFormation][4];
	int hFinCreneauCourant = formation[idFormation][5];

	//on parcours la solution pour trouver les creneaux de formation où l'interface est déjà affectée
	for(int i=0; dispo && i<taille; i++){
		//on verfife la compatibilite des horaires

		//si l'interface est deja affectee a une formation ce jour là
		if(genes[i] != -1 && i != idFormation && genes[i] == idIntervenant && formation[i][3] == jCreneauCourant){
			//on verfife la compatibilite des horaires
			int centreCreneauAffecte = formation[i][1];
			int hDebutCreneauAffecte = formation[i][4];
			int hFinCreneauAffecte = formation[i][5];

			if((hFinCreneauAffecte > hDebutCreneauCourant) && (hDebutCreneauAffecte < hFinCreneauCourant)){
				dispo = false;
			}

			//si le centre de formation est le même
			//l'heure de debut et l'heure de fin de deux creneaux qui se suivent peuvent être la même
			//sinon ce n'est pas possible car il ya le temps de trajet entre les deux centre
			else if( (centreCreneauAffecte != centreCreneauCourant) && 
				((hFinCreneauAffecte == hDebutCreneauCourant) || (hDebutCreneauAffecte == hFinCreneauCourant)) ){
				dispo = false;
			}
		}
	}

	return dispo;
}

//vérifie la validité d'une solution
bool chromosome::valide(){

	bool valide = true;

	//on parcourt la liste des apprenants pour verifier que l'intervenant qui lui est affecté réponds aux critères de validité
	for(int i=0; valide && i<taille; i++){

		int idIntervenant = genes[i];

		//l'intervenant doit posseder la bonne compétence
		int competenceApprenant = formation[i][2];
		valide  = competences_interfaces[idIntervenant][competenceApprenant];

		//l'intervenant doit être disponible sur le creneau horaire de la formation
		valide = valide && interfaceDispo(idIntervenant, i);

		//l'intervenant ne doit pas depasser les 35h
		valide = valide && (tempsRestantIntervenants[idIntervenant] >= 0);
	}

	return valide;
}

// �valuation d'une solution : fonction qui calcule la fitness d'une solution
void chromosome::evaluer(int **distance)
{
	fitness = 0;
	for(int i=0;i<taille-1;i++)
		fitness += distance[genes[i]][genes[i+1]];
	fitness += distance[genes[0]][genes[taille-1]];
}

// copie les genes d'un chromosome. la fitness n'est reprise
void chromosome::copier(chromosome* source)
{
	for(int i=0; i<taille; i++)
		genes[i] = source->genes[i];
}

// on �change les 2 g�nes
void chromosome::echange_2_genes(int gene1, int gene2)
{
	int inter    = genes[gene1];
	genes[gene1] = genes[gene2];
	genes[gene2] = inter;
}

void chromosome::echange_2_genes_consecutifs()
{
	// on s�l�ctionne un g�ne al�atoirement entre premier et l'avant dernier.
	// Rappel : Random::aleatoire(taille-1) retourne un entier al�atoire compris entre 0 et taille-2
	int i = Random::aleatoire(taille-1);

	// on �change le g�ne s�l�ctionn� al�atoirement avec le g�ne le succ�dant
	echange_2_genes(i, i+1);

	//ordonner();
}

void chromosome::echange_2_genes_quelconques()
{
	//on selectionne deux genes aleatoirement entre le premier et le dernier gene du chromosome
	int i = Random::aleatoire(taille);
	int j = Random::aleatoire(taille);
	//on s'assure qu'il s'agit bien de deux genes differents
	while (i==j){
		j = Random::aleatoire(taille);
	}

	//puis on echange les deux genes
	echange_2_genes(i, j);

	//ordonner();
}

void chromosome::deplacement_1_gene()
{
	//on selection un gene et une position aleatoirement
	int i = Random::aleatoire(taille);
	int pos = Random::aleatoire(taille);
	//on s'assure que la position n'est pas celle du gene que l'on doit deplacer
	while (i==pos){
		pos = Random::aleatoire(taille);
	}

	//puis on insert le gene en décalant les genes qui se trouvent entre l'ancienne et la nouvelle position
	if (pos < i) {
		int debut = pos;
		int fin = i;

		int geneI = genes[i];
		int geneD = genes[debut];
		genes[debut] = geneI;
		for(int j = debut; j <= fin; j++){
			int tmp = genes[j];
			genes[j] = genes[i];
			geneI = tmp;
		}
	}
	else{
		int debut = i;
		int fin = pos;

		int geneI = genes[i];
		for(int j = debut; j < fin; j++){
			genes[j] = genes[j+1];
		}
		genes[fin] = geneI;
	}

	


}

void chromosome::inversion_sequence_genes()
{
}

// affichage des param�tre d'un chromosome
void chromosome::afficher()
{
	cout << genes[0];
	for(int i=1;i<taille;i++)
		cout << "-" << genes[i];
	cout << " => fitness = " << fitness << endl;
}

bool chromosome::identique(chromosome* chro)
{
	for(int i=1; i<taille; i++)
		if (chro->genes [i] != this->genes[i])
			return false;
	return true;
}
