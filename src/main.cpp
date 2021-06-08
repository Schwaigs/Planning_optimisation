#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "AlgoGenetic.h"
#include "Chromosome.h"
#include "Random.h"
#include "instancesFormations/instance-80formations_5.h"

using namespace std;

int main(int argc, char **argv)
// argc : nombre de parametres
// argv : tableau contenant les parametres

// Soit l'executable 'main' ne prend pas d'arguments soit il prend 3 arguments :
//    1. taille de la population (entier > 0)
//    2. taux de croisement (0 <= reel <= 1)
//    3. taux de mutation (0 <= reel <= 1)
{
	//initialise le g�n�rateur de nombre al�atoire
	Random::randomize();

	// valeurs par defaut
	int taille_population = NBR_FORMATIONS;
	float taux_croisement = 0.5;
	float taux_mutation   = 0.01;
	int taille_chromosome = NBR_FORMATIONS;

	if (argc == 4)
	{
		taille_population = atoi(argv[1]);
		taux_croisement   = atof(argv[2]);
		taux_mutation     = atof(argv[3]);
		//la taille d'un chromosome n'est pas modifiable
	}
	else if (argc == 1)
	{
		cout << "Parametres par default" << endl;
	}
	else
	{
		cout << "Nombre d'arguments n'est pas correct." << endl;
		cout << "Soit l'executable 'main' ne prend pas d'arguments soit il prend 3 arguments : " << endl;
		cout << "   1. taille de la population (entier > 0)" << endl;
		cout << "   2. taux de croisement (0 <= reel <= 1)" << endl;
		cout << "   3. taux de mutation (0 <= reel <= 1)" << endl;
		exit(EXIT_FAILURE);
	}

	cout << "La taille de la population est de " << taille_population << endl;
	cout << "Le taux de croisement est de " << taux_croisement << endl;
	cout << "Le taux de mutation est de " << taux_mutation << endl;
	cout << "Il y a " << NBR_APPRENANTS << " apprenants suivant chacun " << NBR_FORMATIONS_APPRENANT << " formation(s). La taille d'un chromosome est donc de " << taille_chromosome << endl;
	cout << "Il y a " << NBR_CENTRES_FORMATION << " centres de formations " << endl << endl;

	// initialise l'algorithme �volutionniste
	AlgoGenetic algo(taille_population, taux_croisement, taux_mutation, taille_chromosome);
	// arguments du constructeur de l'objet AlgoGenetic
	//    1. taille de la population (entier > 0)
	//    2. taux de croisement (0 <= reel <= 1)
	//    3. taux de mutation (0 <= reel <= 1)
	//    4. nombre de formation (=taille d'un chromosome)

	// lance l'algorithme �volutionniste
	Chromosome *best = algo.optimiser();

	//affiche la fitness du meilleur individu trouvé
	cout << "La meilleure solution trouvee est : ";
	best->afficher();
}
