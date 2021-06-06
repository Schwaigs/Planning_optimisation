#ifndef POPULATION_H
#define POPULATION_H

#include <math.h>
#include <stdio.h>
#include <iostream>
#include "chromosome.h"

// La classe population englobe plusieurs solution potentielle du probleme
class population{
public:
    // ATTRIBUTS
	chromosome **individus;  // liste des individus de la population
	int taille_pop;          // nombre d'individus de la population
	int *ordre;              // tableau donnant l'ordre des individus dans la population
                             //   du meilleur au plus mauvais en fonction de la fitness	population(int tp, int tc);    // constructeur de l'objet

	// CONSTRUCTEURS
	population(int tp, int tc); // constructeur de l'objet
	~population(); // destructeur de l'objet

	// METHODES
	void statistiques(); // affiche quelques statistiques sur la population
	int nb_chromosomes_similaires(chromosome* chro);  // compte le nombre de chromosomes similaires � 'chro'
	void similitude();   // affiche les r�sultats du comptage de chromosomes similaires
	                     // aux meilleurs individus de la population.

    // OPERATEURS DE SELECTION ET DE REMPLACEMENT
    chromosome *selection_tournoi();
    void remplacement_tournoi(chromosome *individu);

    int in_list(int index, chromosome** individusTires, int taille);
    void ordonner();
    void reordonner();
};

# endif
