#include "instance-100formations_5.h"

/* competences des interfaces en SIGNES et CODAGE*/
int competences_interfaces[NBR_INTERFACES][2]={
    {1,0}, /* compétence en langages des SIGNES mais pas en CODAGE LPC */
    {0,1}, /* pas de compétence en langages des SIGNES mais compétence en CODAGE LPC */
    {1,0},
    {0,1},
    {1,0},
    {1,0},
    {1,0},
    {0,1},
    {1,0},
    {1,0},
    {1,1},
    {1,0},
    {1,1},
    {1,0},
    {0,1},
    {0,1},
    {1,0},
    {0,1},
    {0,1},
    {0,1},
    {0,1},
    {0,1},
    {1,0},
    {0,1},
    {1,0},
    {1,0},
    {0,1},
    {1,0},
    {1,0},
    {0,1}
};

/* specialite des interfaces */
int specialite_interfaces[NBR_INTERFACES][NBR_SPECIALITES]={
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {1,0,1,0,0},
    {0,1,0,0,0},
    {0,0,0,0,1},
    {0,0,0,0,0},
    {0,0,0,0,1},
    {1,0,0,0,0},
    {0,0,0,0,1},
    {0,0,0,0,1},
    {0,0,0,1,1},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {1,1,1,0,0},
    {1,1,0,0,0},
    {1,0,0,1,1},
    {0,0,0,0,0},
    {1,0,0,0,0},
    {1,0,0,0,0},
    {0,0,0,1,1},
    {1,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,1,0},
    {0,0,1,0,1},
    {1,0,0,0,0},
    {0,0,0,0,0},
    {0,0,1,1,0},
    {1,0,0,1,0}
};
                  
/* coordonnées des centres de formation, des interfaces et des apprenants */
float coord[NBR_CENTRES_FORMATION+1][2]={
                  
    /* Les interfaces se rendent du centre SESSAD à l'école de formation */
    {19,99}, /* centre 0 */
                  
    /* Centres de formation */
    {26,192}, /* ecole formation SPECIALITE_MENUISERIE */
    {46,70}, /* ecole formation SPECIALITE_ELECTRICITE */
    {95,189}, /* ecole formation SPECIALITE_MECANIQUE */
    {131,151}, /* ecole formation SPECIALITE_INFORMATIQUE */
    {178,8} /* ecole formation SPECIALITE_CUISINE */
};

/* formation : id formation, specialite ou centre de formation, competence, horaire debut formation, horaire fin formation */
int formation[NBR_APPRENANTS][NBR_FORMATIONS_APPRENANT][6]={
    {
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,JEUDI,9,11}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_CODAGE,MERCREDI,10,12}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,LUNDI,14,16}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,JEUDI,15,19}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MERCREDI,9,11}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,MARDI,9,12}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,JEUDI,10,12}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,MARDI,15,19}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,MERCREDI,9,12}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,LUNDI,10,12}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,LUNDI,14,19}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_CODAGE,JEUDI,16,19}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,JEUDI,10,12}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,LUNDI,10,12}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,JEUDI,16,19}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,LUNDI,10,12}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,VENDREDI,8,10}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,SAMEDI,10,12}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,MARDI,9,11}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,VENDREDI,13,19}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,MARDI,8,10}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,JEUDI,10,12}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,MARDI,16,19}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,LUNDI,10,12}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_CODAGE,VENDREDI,9,12}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,LUNDI,10,12}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,SAMEDI,9,12}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_CODAGE,SAMEDI,9,12}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_CODAGE,LUNDI,16,18}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MERCREDI,14,16}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,JEUDI,9,11}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,MERCREDI,10,12}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,LUNDI,15,17}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_CODAGE,VENDREDI,15,17}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,SAMEDI,13,19}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_SIGNES,VENDREDI,10,12}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,SAMEDI,9,11}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_SIGNES,MARDI,13,17}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,LUNDI,15,17}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,JEUDI,8,10}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_SIGNES,MARDI,8,10}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MARDI,9,12}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,LUNDI,9,11}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,SAMEDI,15,17}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_SIGNES,MARDI,14,18}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,MARDI,13,18}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,JEUDI,14,19}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,LUNDI,9,12}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_SIGNES,VENDREDI,9,12}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,MERCREDI,15,18}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,JEUDI,16,18}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,SAMEDI,10,12}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,LUNDI,16,19}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,VENDREDI,16,18}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,LUNDI,9,12}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,SAMEDI,8,10}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,MERCREDI,13,18}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,MARDI,8,10}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,SAMEDI,15,19}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,JEUDI,16,18}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,JEUDI,10,12}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,MARDI,15,19}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,JEUDI,14,18}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MARDI,13,19}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MERCREDI,10,12}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,SAMEDI,16,18}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,VENDREDI,14,18}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MERCREDI,16,18}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_CODAGE,LUNDI,15,18}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,VENDREDI,8,11}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,VENDREDI,8,12}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,VENDREDI,16,18}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MERCREDI,10,12}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MERCREDI,10,12}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,MARDI,16,19}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_CODAGE,LUNDI,13,16}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,JEUDI,10,12}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,MERCREDI,10,12}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,MERCREDI,10,12}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,LUNDI,9,12}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_SIGNES,MERCREDI,8,12}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,VENDREDI,8,10}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_CODAGE,LUNDI,10,12}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,SAMEDI,8,10}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,LUNDI,15,17}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,VENDREDI,16,19}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_CODAGE,LUNDI,13,18}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,LUNDI,15,18}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,MERCREDI,16,18}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,LUNDI,8,10}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,MERCREDI,9,11}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,MARDI,13,16}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,MERCREDI,9,11}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,MARDI,14,17}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,MERCREDI,9,12}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,VENDREDI,10,12}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,MARDI,9,12}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,LUNDI,16,18}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_SIGNES,LUNDI,14,16}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,MARDI,9,11}
    }
};
