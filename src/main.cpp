#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include "ae.h"
#include "chromosome.h"
#include "random.h"
#include "instance-80formations.h"

using namespace std;

int main(int argc, char **argv)
// argc : nombre de parametres
// argv : tableau contenant les parametres

// Soit l'executable 'algo_evo' ne prend pas d'arguments soit il prend 5 arguments :
//    1. nombre de g�n�ration (entier > 0)
//    2. taille de la population (entier > 0)
//    3. taux de croisement (0 <= reel <= 1)
//    4. taux de mutation (0 <= reel <= 1)
//    5. nombre de villes (=taille d'un chromosome)
{
	//initialise le g�n�rateur de nombre al�atoire
	Random::randomize();

	// valeurs par defaut
	int nb_generation     = 50;
	int taille_population = NBR_FORMATIONS * 2;
	float taux_croisement = 0.8;
	float taux_mutation   = 0.5;
	int taille_chromosome = NBR_FORMATIONS;

	if (argc == 6)
	{
		nb_generation     = atoi(argv[1]);
		taille_population = atoi(argv[2]);
		taux_croisement   = atof(argv[3]);
		taux_mutation     = atof(argv[4]);
		taille_chromosome = atoi(argv[5]);
	}
	else if (argc == 1)
	{
		cout << "Parametres par default" << endl;
	}
	else
	{
		cout << "Nombre d'arguments n'est pas correct." << endl;
		cout << "Soit l'executable 'algo_evo' ne prend pas d'arguments soit il prend 5 arguments : " << endl;
		cout << "   1. nombre de g�n�ration (entier > 0)" << endl;
		cout << "   2. taille de la population (entier > 0)" << endl;
		cout << "   3. taux de croisement (0 <= reel <= 1)" << endl;
		cout << "   4. taux de mutation (0 <= reel <= 1)" << endl;
		cout << "   5. nombre de formation (=taille d'un chromosome)" << endl;
		exit(EXIT_FAILURE);
	}

	// initialise l'algorithme �volutionniste
	Ae algo(nb_generation, taille_population, taux_croisement, taux_mutation, taille_chromosome);
	// arguments du constructeur de l'objet Ae
	//    1. nombre de g�n�ration (entier > 0)
	//    2. taille de la population (entier > 0)
	//    3. taux de croisement (0 <= reel <= 1)
	//    4. taux de mutation (0 <= reel <= 1)
	//    5. nombre de formation (=taille d'un chromosome)

	// lance l'algorithme �volutionniste
	//chromosome *best = algo.optimiser();

	// affiche la fitness du meilleur individu trouv�
	//cout << "La meilleure solution trouvee est : ";
	//best->afficher();
}
