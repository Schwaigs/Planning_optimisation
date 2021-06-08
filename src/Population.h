#ifndef POPULATION_H
#define POPULATION_H

#include <math.h>
#include <stdio.h>
#include <iostream>
#include "Chromosome.h"

// La classe Population englobe plusieurs solution potentielle du probleme
class Population{
public:
    // ATTRIBUTS
	Chromosome **individus;  // liste des individus de la population
	int taille_pop;          // nombre d'individus de la population
	int *ordre;              // tableau donnant l'ordre des individus dans la population
                             //   du meilleur au plus mauvais en fonction de la fitness	Population(int tp, int tc);    // constructeur de l'objet

	// CONSTRUCTEURS
	Population(int tp, int tc); // constructeur de l'objet
	~Population(); // destructeur de l'objet

	// METHODES
	void statistiques(); // affiche quelques statistiques sur la population

    // OPERATEURS DE SELECTION ET DE REMPLACEMENT
    Chromosome *selection_tournoi();
    void remplacement_tournoi(Chromosome *individu);

    int in_list(int index, Chromosome** individusTires, int taille);
    void ordonner();
    void reordonner();
};

# endif
