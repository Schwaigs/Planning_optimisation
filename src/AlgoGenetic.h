#ifndef _ALGOGENETIC_H
#define _ALGOGENETIC_H

#include <math.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Population.h"
#include "Chromosome.h"
#include "instancesFormations/instance-80formations_5.h"

using namespace std;
// La classe AlgoGenetic d�finie les param�tres d'une ex�cution d'un algorithme
//    �volutionniste ainsi que la proc�dure principale de recherche
class AlgoGenetic{
public:
    // ATTRIBUTS
	int taille_pop;          // nombre d'individus dans la population
	double taux_croisement;  // taux de croisement : valeur entre 0 et 1
	double taux_mutation;    // taux de mutation : valeur entre 0 et 1
	int taille_chromosome;   // nombre de g�nes dans le chromosome
	Population *pop;         // liste des individus de la population

	// CONSTRUCTEURS
	AlgoGenetic(int tp, double tcroisement, double tmutation, int tc);// constructeur de l'objet Algaorithme evolutioniste
	~AlgoGenetic(); // destructeur de l'objet AlgoGenetic

	// METHODES
	// fonction principale qui d�cit le d�roulement de l'algorithme �volusionniste
	Chromosome* optimiser();
	//fonction qui trie dans l'ordre croissant un tableau d'entier d'une taille donnée
	void sort(int* tab, int size);
	//fonction qui vérifie si un élément passé en paramètre se situe dans un tableau d'entier également passé en paramètre
	bool isInArray(int value, int* tab, int size);
	// OPERATEURS DE CROISEMENT
	// double croisement NX de deux chromosomes
	void croisementDoubleNX(Chromosome* parent1, Chromosome* parent2,
													Chromosome* enfant1, Chromosome* enfant2);
	// opérateur de croisement NX de deux chromosomes
	void croisementNX(Chromosome* parent1, Chromosome* parent2,
													Chromosome* enfant1, Chromosome* enfant2, int croisementN);
};

# endif
