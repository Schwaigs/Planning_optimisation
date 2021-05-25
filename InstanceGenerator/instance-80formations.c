#include <stdio.h>
                  
#define NBR_INTERFACES        24
#define NBR_APPRENANTS        80
#define NBR_FORMATIONS        80
#define NBR_CENTRES_FORMATION 5
#define NBR_SPECIALITES       5
#define NBR_NODES 	      NBR_CENTRES_FORMATION+NBR_INTERFACES+NBR_APPRENANTS
                  
/* code des compétence en langage des signes et en codage LPC */
#define COMPETENCE_SIGNES     0
#define COMPETENCE_CODAGE     1
                  
/* competences des interfaces en SIGNES et CODAGE*/
int competences_interfaces[NBR_INTERFACES][2]={
    {1,0}, /* compétence en langages des SIGNES mais pas en CODAGE LPC */
    {0,1}, /* pas de compétence en langages des SIGNES mais compétence en CODAGE LPC */
    {0,1},
    {0,1},
    {1,1},
    {1,1},
    {1,0},
    {1,0},
    {1,0},
    {1,0},
    {0,1},
    {0,1},
    {1,0},
    {1,0},
    {0,1},
    {1,0},
    {1,0},
    {0,1},
    {0,1},
    {0,1},
    {0,1},
    {1,0},
    {0,1},
    {0,1}
};
                  
/* spécialités des interfaces */
#define SPECIALITE_SANS       -1 /* Enseigné dans le centre le plus proche */
#define SPECIALITE_MENUISERIE 0
#define SPECIALITE_ELECTRICITE 1
#define SPECIALITE_MECANIQUE 2
#define SPECIALITE_INFORMATIQUE 3
#define SPECIALITE_CUISINE 4
                  
/* specialite des interfaces */
int specialite_interfaces[NBR_INTERFACES][NBR_SPECIALITES]={
    {0,0,0,0,1},
    {1,0,1,0,1},
    {1,1,0,0,0},
    {0,0,1,0,0},
    {0,1,0,0,1},
    {0,0,0,0,0},
    {0,0,0,0,1},
    {0,0,0,0,0},
    {0,0,0,1,0},
    {1,0,0,0,0},
    {0,0,0,0,0},
    {1,1,0,0,0},
    {0,1,0,0,0},
    {0,0,1,0,0},
    {1,0,0,0,1},
    {0,0,0,0,0},
    {0,1,0,0,1},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,1,0},
    {0,0,1,0,0},
    {0,0,0,0,0},
    {0,0,1,0,0}
};
                  
/* coordonnées des centres de formation, des interfaces et des apprenants */
float coord[NBR_NODES][2]={
                  
    /* Les interfaces se rendent du centre SESSAD à l'école de formation */
    {161,133}, /* centre 0 */
                  
    /* Centres de formation */
    {160,87}, /* ecole formation SPECIALITE_MENUISERIE */
    {50,193}, /* ecole formation SPECIALITE_ELECTRICITE */
    {74,144}, /* ecole formation SPECIALITE_MECANIQUE */
    {47,113}, /* ecole formation SPECIALITE_INFORMATIQUE */
    {102,9}, /* ecole formation SPECIALITE_CUISINE */
                  
    /* Apprenants */
    {66,167}, /* apprenant 0 */
    {133,75}, /* apprenant 1 */
    {44,31}, /* apprenant 2 */
    {156,82}, /* apprenant 3 */
    {106,25}, /* apprenant 4 */
    {95,57}, /* apprenant 5 */
    {68,179}, /* apprenant 6 */
    {147,81}, /* apprenant 7 */
    {4,192}, /* apprenant 8 */
    {93,92}, /* apprenant 9 */
    {126,115}, /* apprenant 10 */
    {168,31}, /* apprenant 11 */
    {149,66}, /* apprenant 12 */
    {10,28}, /* apprenant 13 */
    {133,53}, /* apprenant 14 */
    {37,50}, /* apprenant 15 */
    {59,66}, /* apprenant 16 */
    {48,9}, /* apprenant 17 */
    {104,195}, /* apprenant 18 */
    {181,91}, /* apprenant 19 */
    {172,23}, /* apprenant 20 */
    {132,46}, /* apprenant 21 */
    {41,129}, /* apprenant 22 */
    {173,144}, /* apprenant 23 */
    {18,91}, /* apprenant 24 */
    {5,110}, /* apprenant 25 */
    {83,113}, /* apprenant 26 */
    {13,120}, /* apprenant 27 */
    {158,17}, /* apprenant 28 */
    {122,164}, /* apprenant 29 */
    {143,86}, /* apprenant 30 */
    {77,59}, /* apprenant 31 */
    {129,22}, /* apprenant 32 */
    {108,36}, /* apprenant 33 */
    {95,114}, /* apprenant 34 */
    {123,7}, /* apprenant 35 */
    {108,42}, /* apprenant 36 */
    {164,81}, /* apprenant 37 */
    {35,16}, /* apprenant 38 */
    {181,96}, /* apprenant 39 */
    {10,92}, /* apprenant 40 */
    {108,189}, /* apprenant 41 */
    {185,172}, /* apprenant 42 */
    {9,56}, /* apprenant 43 */
    {53,182}, /* apprenant 44 */
    {137,13}, /* apprenant 45 */
    {56,165}, /* apprenant 46 */
    {49,17}, /* apprenant 47 */
    {193,58}, /* apprenant 48 */
    {72,77}, /* apprenant 49 */
    {150,156}, /* apprenant 50 */
    {69,123}, /* apprenant 51 */
    {158,105}, /* apprenant 52 */
    {98,128}, /* apprenant 53 */
    {102,149}, /* apprenant 54 */
    {113,99}, /* apprenant 55 */
    {7,166}, /* apprenant 56 */
    {49,88}, /* apprenant 57 */
    {55,136}, /* apprenant 58 */
    {50,19}, /* apprenant 59 */
    {12,129}, /* apprenant 60 */
    {153,82}, /* apprenant 61 */
    {61,182}, /* apprenant 62 */
    {48,98}, /* apprenant 63 */
    {106,134}, /* apprenant 64 */
    {186,196}, /* apprenant 65 */
    {4,143}, /* apprenant 66 */
    {162,61}, /* apprenant 67 */
    {4,146}, /* apprenant 68 */
    {42,127}, /* apprenant 69 */
    {147,183}, /* apprenant 70 */
    {60,19}, /* apprenant 71 */
    {121,55}, /* apprenant 72 */
    {193,99}, /* apprenant 73 */
    {74,65}, /* apprenant 74 */
    {175,86}, /* apprenant 75 */
    {97,132}, /* apprenant 76 */
    {113,98}, /* apprenant 77 */
    {59,92}, /* apprenant 78 */
    {11,195}/* apprenant 79 */
};
                  
#define NBR_FORMATION          80
                  
#define LUNDI                  1
#define MARDI                  2
#define MERCREDI               3
#define JEUDI                  4
#define VENDREDI               5
#define SAMEDI                 6
                  
/* formation : id formation, specialite ou centre de formation, competence, horaire debut formation, horaire fin formation */
int formation[NBR_FORMATION][6]={
   {0,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,JEUDI,14,19},
   {1,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,LUNDI,10,12},
   {2,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,VENDREDI,14,19},
   {3,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,SAMEDI,16,19},
   {4,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,MARDI,10,12},
   {5,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,LUNDI,14,17},
   {6,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,JEUDI,8,10},
   {7,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,VENDREDI,15,19},
   {8,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MERCREDI,9,11},
   {9,SPECIALITE_CUISINE,COMPETENCE_CODAGE,LUNDI,14,19},
   {10,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,MARDI,14,16},
   {11,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,JEUDI,10,12},
   {12,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,SAMEDI,13,18},
   {13,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,VENDREDI,14,17},
   {14,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MARDI,9,12},
   {15,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,SAMEDI,8,11},
   {16,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,SAMEDI,9,11},
   {17,SPECIALITE_CUISINE,COMPETENCE_CODAGE,LUNDI,16,19},
   {18,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,MERCREDI,13,17},
   {19,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,LUNDI,8,12},
   {20,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,VENDREDI,10,12},
   {21,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,MERCREDI,13,19},
   {22,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,SAMEDI,10,12},
   {23,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,VENDREDI,14,18},
   {24,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,MERCREDI,16,19},
   {25,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,SAMEDI,9,11},
   {26,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,JEUDI,16,19},
   {27,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,SAMEDI,13,18},
   {28,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,VENDREDI,16,18},
   {29,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,SAMEDI,9,12},
   {30,SPECIALITE_CUISINE,COMPETENCE_CODAGE,JEUDI,9,11},
   {31,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,MARDI,8,10},
   {32,SPECIALITE_CUISINE,COMPETENCE_SIGNES,VENDREDI,16,19},
   {33,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,JEUDI,8,10},
   {34,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,LUNDI,13,16},
   {35,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,MARDI,8,12},
   {36,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,MARDI,8,11},
   {37,SPECIALITE_CUISINE,COMPETENCE_SIGNES,MARDI,9,11},
   {38,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,SAMEDI,10,12},
   {39,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,VENDREDI,16,19},
   {40,SPECIALITE_CUISINE,COMPETENCE_SIGNES,MARDI,9,11},
   {41,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,LUNDI,13,15},
   {42,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,SAMEDI,14,16},
   {43,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,JEUDI,13,15},
   {44,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,JEUDI,14,16},
   {45,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,VENDREDI,14,16},
   {46,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,SAMEDI,15,18},
   {47,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,MARDI,15,18},
   {48,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,MARDI,8,11},
   {49,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,VENDREDI,10,12},
   {50,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,JEUDI,16,19},
   {51,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,LUNDI,9,11},
   {52,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,SAMEDI,15,18},
   {53,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,LUNDI,16,18},
   {54,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,LUNDI,15,18},
   {55,SPECIALITE_CUISINE,COMPETENCE_SIGNES,SAMEDI,8,10},
   {56,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,SAMEDI,14,19},
   {57,SPECIALITE_CUISINE,COMPETENCE_CODAGE,VENDREDI,13,18},
   {58,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,SAMEDI,10,12},
   {59,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,LUNDI,10,12},
   {60,SPECIALITE_CUISINE,COMPETENCE_SIGNES,MERCREDI,10,12},
   {61,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,SAMEDI,16,19},
   {62,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,VENDREDI,9,12},
   {63,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,MARDI,13,15},
   {64,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,VENDREDI,13,19},
   {65,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,JEUDI,13,16},
   {66,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,VENDREDI,13,16},
   {67,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,LUNDI,9,11},
   {68,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,LUNDI,16,19},
   {69,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,JEUDI,8,11},
   {70,SPECIALITE_CUISINE,COMPETENCE_CODAGE,LUNDI,8,11},
   {71,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,MERCREDI,8,10},
   {72,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,VENDREDI,9,11},
   {73,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,JEUDI,8,11},
   {74,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,VENDREDI,8,11},
   {75,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,MERCREDI,16,19},
   {76,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,LUNDI,9,11},
   {77,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,LUNDI,15,19},
   {78,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,MARDI,16,18},
   {79,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,SAMEDI,9,12}
};
                  
int main() {
                  
    printf("NBR_INTERFACES=%d\n",NBR_INTERFACES) ;
    printf("NBR_APPRENANTS=%d\n",NBR_APPRENANTS) ;
    printf("NBR_FORMATIONS=%d\n",NBR_FORMATIONS) ;
    printf("NBR_NODES=%d\n",NBR_NODES) ;
                  
    return 0 ;
}
                  
