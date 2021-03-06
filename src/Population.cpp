#include "Population.h"

using namespace std;

// initialisation d'une population de solutions
Population::Population(int tp, int tc)
{
	taille_pop = tp;
	individus  = new Chromosome*[taille_pop];
	for (int i=0; i<taille_pop; i++)
		individus[i] = new Chromosome(tc);
	ordre = new int[taille_pop];
}

// destruction de l'objet "Population"
Population::~Population()
{
	for (int i=0; i<taille_pop; i++)
		delete individus[i];
	delete individus;
	delete ordre;
}

// statistiques sur la population
void Population::statistiques()
{
	double moyenne    = 0;
	double ecart_type = 0;

	for (int i=0; i<taille_pop; i++)
	{
		moyenne += individus[i]->fitness;
		ecart_type += individus[i]->fitness*individus[i]->fitness;
	}
	moyenne = moyenne / taille_pop;
	ecart_type = sqrt(ecart_type/taille_pop - moyenne*moyenne);

	cout << "fitness : (moyenne, ecart_type) -> ("
	     <<  moyenne << " , "  << ecart_type << ")" << endl;
	cout << "fitness : [meilleure, mediane, pire] -> ["
	     << individus[ordre[0]]->fitness << " , "
	     << individus[ordre[(int)(taille_pop/2)]]->fitness << " , "
	     << individus[ordre[taille_pop-1]]->fitness << "]" << endl;
}

// Ordonne les individus de la population par ordre croissant de fitness
void Population::ordonner()
{
	int inter;
	for(int i=0; i<taille_pop; i++)
		ordre[i]=i;

	for(int i=0; i<taille_pop-1; i++)
		for(int j=i+1; j<taille_pop; j++)
			if(individus[ordre[i]]->fitness > individus[ordre[j]]->fitness)
			{
				inter    = ordre[i];
				ordre[i] = ordre[j];
				ordre[j] = inter;
			}
}

// R�-ordonne le classement des individus de la population par ordre croissant de fitness
//   apr�s un petit changement
void Population::reordonner()
{
	int inter;
	for(int i=0; i<taille_pop-1; i++)
		for(int j=i+1; j<taille_pop; j++)
			if(individus[ordre[i]]->fitness > individus[ordre[j]]->fitness)
			{
				inter    = ordre[i];
				ordre[i] = ordre[j];
				ordre[j] = inter;
			}
}

// SELECTION PAR TOURNOI
//op�rateur de s�lection bas� sur la fonction fitness
Chromosome* Population::selection_tournoi()
{
    int n = taille_pop/10; //nombre d'individus tirés
	Chromosome* chromosomeFitnessMin;
    int index_indiv; //index de l'individu tiré
    Chromosome* individusTires[n];
    //tirage de n individus

    for(int i = 0; i<n; i++){
        do
        {
            index_indiv = (rand()%taille_pop-2)+1;
        } while (index_indiv==-1 && in_list(index_indiv, individusTires, n));
        individusTires[i] = individus[index_indiv];
    }
    chromosomeFitnessMin = individusTires[0];

    for(int i=0; i<n; i++){
        if(individusTires[i]->fitness < chromosomeFitnessMin->fitness){
            chromosomeFitnessMin = individusTires[i];
        }
    }

    return chromosomeFitnessMin;
}

int Population::in_list(int index, Chromosome** individusTires, int taille){
    if(index<0){
        return 1;
    }
    for(int i = 0; i<taille; i++){
        if (individus[index] == individusTires[i]){
            return 1;
        }
    }
    return 0;
}

void Population::remplacement_tournoi(Chromosome* individu){
    int n = taille_pop/10; //nombre d'individus tirés
	Chromosome* chromosomeFitnessMax;
    int index_indiv; //index de l'individu tiré
    int index_max=-1;
    Chromosome* individusTires[n];

    //tirage de n individus
    for(int i = 0; i<n; i++){
        do
        {
            index_indiv = (rand()%taille_pop-2)+1;
        } while (index_indiv==-1 && in_list(index_indiv, individusTires, n));
        if (index_max==-1)
        {
            index_max=index_indiv;
        }else if(individus[index_max]->fitness<individus[index_indiv]->fitness){
            index_max = index_indiv;
        }
    }

	individus[index_max]->copier(individu);
	individus[index_max]->fitness = individu->fitness;
	individus[index_max]->majTempsTravailInterface();
}
