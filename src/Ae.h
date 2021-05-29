#ifndef _AE_H
#define _AE_H

#include <math.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "population.h"
#include "chromosome.h"

using namespace std;
// La classe Ae définie les paramètres d'une exécution d'un algorithme
//    évolutionniste ainsi que la procédure principale de recherche
class Ae{
public:
    // ATTRIBUTS
	int nbgenerations;       // nombre de générations après quoi la recherche est arrétée
	int taille_pop;          // nombre d'individus dans la population
	double taux_croisement;  // taux de croisement : valeur entre 0 et 1
	double taux_mutation;    // taux de mutation : valeur entre 0 et 1
	int taille_chromosome;   // nombre de gènes dans le chromosome
	population *pop;         // liste des individus de la population
    int **les_distances;     // matrice des distances entre les villes

	// CONSTRUCTEURS
	Ae(int nbg, int tp, double tcroisement, double tmutation, int tc, char* nom_fichier);
                             // constructeur de l'objet Algaorithme evolutioniste
	~Ae();                   // destructeur de l'objet Ae

	// METHODES
	void constuction_distance(char* nom_fichier);
                             // constuie la matrice des distances
	chromosome* optimiser(); // fonction principale qui décit le déroulement de l'algorithme évolusionniste

	// OPERATEURS DE CROISEMENT
	// opérateur de croisement 1X de deux chromosomes
    void croisement1X(chromosome* parent1, chromosome* parent2,
                      chromosome* enfant1, chromosome* enfant2);
	// opérateur de croisement 1X de deux chromosomes
    void croisement2X(chromosome* parent1, chromosome* parent2,
                      chromosome* enfant1, chromosome* enfant2);
	// opérateur de croisement 2LOX de deux chromosomes
    void croisement2LOX(chromosome* parent1, chromosome* parent2,
                        chromosome* enfant_s1, chromosome* enfant_s2);
};

# endif
