#pragma once

#include <stdio.h>
                  
#define NBR_INTERFACES        44
#define NBR_APPRENANTS        150
#define NBR_FORMATIONS_APPRENANT    1
#define NBR_FORMATIONS              NBR_APPRENANTS*NBR_FORMATIONS_APPRENANT
#define NBR_CENTRES_FORMATION 5
#define NBR_SPECIALITES       5
                  
/* code des compétence en langage des signes et en codage LPC */
#define COMPETENCE_SIGNES     0
#define COMPETENCE_CODAGE     1
                  
/* competences des interfaces en SIGNES et CODAGE*/
extern int competences_interfaces[NBR_INTERFACES][2];
                  
/* spécialités des interfaces */
#define SPECIALITE_SANS       -1 /* Enseigné dans le centre le plus proche */
#define SPECIALITE_MENUISERIE 0
#define SPECIALITE_ELECTRICITE 1
#define SPECIALITE_MECANIQUE 2
#define SPECIALITE_INFORMATIQUE 3
#define SPECIALITE_CUISINE 4
                  
/* specialite des interfaces */
extern int specialite_interfaces[NBR_INTERFACES][NBR_SPECIALITES];
                  
/* coordonnées des centres de formation, des interfaces et des apprenants */
extern float coord[NBR_CENTRES_FORMATION+1][2];
                  
#define NBR_FORMATION          150
                  
#define LUNDI                  1
#define MARDI                  2
#define MERCREDI               3
#define JEUDI                  4
#define VENDREDI               5
#define SAMEDI                 6
                  
/* formation : id formation, specialite ou centre de formation, competence, horaire debut formation, horaire fin formation */
extern int formation[NBR_APPRENANTS][NBR_FORMATIONS_APPRENANT][6];
