#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include <list>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "random.h"
#include "instancesFormations/instance-80formations_5.h"

// La classe chromosome represente la structure d'une solution du probl�me
class chromosome{
public:
    // ATTRIBUTS
	int *genes;         // les g�nes du chromosome/solution
	int taille;         // la taille du chromosome = nombre de g�nes
	int fitness;        // la valeur de la fonction objectif (fitness) de la solution
  int *tempsRestantIntervenants; //le temps de travail encore disponible pour chaque interface

	// CONSTRUCTEURS
	chromosome(int tc); // constructeur de l'objet al�atoirement
	~chromosome();      // destructeur de l'objet

	// METHODES
    bool interfaceDispo(int idIntervenant, int idApprenant, int idCours); //vérifie la disponibilité d'une interface pour un creaneau de formation
    bool valide(); //vérifie la validité d'une solution
	void afficher();    // fonction d'affichage du chromosome (i.e. de la solution)
	void evaluer();
	                    // fonction d'�valuation du chromosome (c-�-d calcul la fitness)
                        //   Elle doit etre lanc�e � la creation des solution et apres
					    //   l'ex�cution des operateurs de mutation et de croisement
    void copier(chromosome* source);  // copie le chromosome 'source'
    bool identique(chromosome* chro); // test si 2 chromosome sont identique
		void shuffle(int *array, size_t n);
    void majTempsTravailInterface(); //met à jour le tableau de temps de travail des interface suite à un changement dans les genes

    // OPERATEURS DE MUTATION
		void melange_alea_genes();
};

# endif
