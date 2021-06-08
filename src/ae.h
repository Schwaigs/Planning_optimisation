#ifndef _AE_H
#define _AE_H

#include <math.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "population.h"
#include "chromosome.h"
#include "instancesFormations/instance-80formations_5.h"

using namespace std;
// La classe Ae d�finie les param�tres d'une ex�cution d'un algorithme
//    �volutionniste ainsi que la proc�dure principale de recherche
class Ae{
public:
    // ATTRIBUTS
	int taille_pop;          // nombre d'individus dans la population
	double taux_croisement;  // taux de croisement : valeur entre 0 et 1
	double taux_mutation;    // taux de mutation : valeur entre 0 et 1
	int taille_chromosome;   // nombre de g�nes dans le chromosome
	population *pop;         // liste des individus de la population

	// CONSTRUCTEURS
	Ae(int tp, double tcroisement, double tmutation, int tc);// constructeur de l'objet Algaorithme evolutioniste
	~Ae(); // destructeur de l'objet Ae

	// METHODES
	// fonction principale qui d�cit le d�roulement de l'algorithme �volusionniste
	chromosome* optimiser();
	//fonction qui trie dans l'ordre croissant un tableau d'entier d'une taille donnée
	void sort(int* tab, int size);
	//fonction qui vérifie si un élément passé en paramètre se situe dans un tableau d'entier également passé en paramètre
	bool isInArray(int value, int* tab, int size);
	// OPERATEURS DE CROISEMENT
	// double croisement NX de deux chromosomes
	void croisementDoubleNX(chromosome* parent1, chromosome* parent2,
													chromosome* enfant1, chromosome* enfant2);
	// opérateur de croisement NX de deux chromosomes
	void croisementNX(chromosome* parent1, chromosome* parent2,
													chromosome* enfant1, chromosome* enfant2, int croisementN);
};

# endif
