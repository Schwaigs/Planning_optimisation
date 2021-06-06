#include "instance-50formations_5.h"

/* competences des interfaces en SIGNES et CODAGE*/
int competences_interfaces[NBR_INTERFACES][2]={
    {1,0}, /* compétence en langages des SIGNES mais pas en CODAGE LPC */
    {0,1}, /* pas de compétence en langages des SIGNES mais compétence en CODAGE LPC */
    {0,1},
    {1,0},
    {1,1},
    {0,1},
    {1,0},
    {1,0},
    {1,0},
    {0,1},
    {0,1},
    {0,1},
    {0,1},
    {1,0}
};

/* specialite des interfaces */
int specialite_interfaces[NBR_INTERFACES][NBR_SPECIALITES]={
    {1,0,0,0,0},
    {1,0,0,0,0},
    {0,0,0,1,1},
    {1,1,1,0,1},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {1,0,0,0,1},
    {1,0,0,0,0},
    {0,1,0,0,0},
    {0,1,1,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,1,0,1,0}
};
                  
/* coordonnées des centres de formation, des interfaces et des apprenants */
float coord[NBR_CENTRES_FORMATION+1][2]={
                  
    /* Les interfaces se rendent du centre SESSAD à l'école de formation */
    {54,26}, /* centre 0 */
                  
    /* Centres de formation */
    {33,166}, /* ecole formation SPECIALITE_MENUISERIE */
    {198,22}, /* ecole formation SPECIALITE_ELECTRICITE */
    {49,149}, /* ecole formation SPECIALITE_MECANIQUE */
    {52,88}, /* ecole formation SPECIALITE_INFORMATIQUE */
    {89,111} /* ecole formation SPECIALITE_CUISINE */
};
   
/* formation : id formation, specialite ou centre de formation, competence, horaire debut formation, horaire fin formation */
int formation[NBR_APPRENANTS][NBR_FORMATIONS_APPRENANT][6]={
    {
        {0,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,JEUDI,9,11}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,SAMEDI,10,12}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,LUNDI,16,18}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,SAMEDI,14,18}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,MARDI,9,11}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,VENDREDI,9,12}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,VENDREDI,9,12}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_CODAGE,JEUDI,15,17}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,SAMEDI,10,12}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,LUNDI,14,19}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,SAMEDI,8,10}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MARDI,13,19}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,MARDI,10,12}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,MARDI,8,12}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,MERCREDI,16,19}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_CODAGE,VENDREDI,14,18}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_SIGNES,JEUDI,13,16}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_CODAGE,JEUDI,15,17}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,MARDI,15,19}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_SIGNES,MERCREDI,16,19}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,LUNDI,8,10}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,MERCREDI,8,11}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,LUNDI,15,18}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_CODAGE,VENDREDI,15,19}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,SAMEDI,15,17}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,JEUDI,14,16}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,VENDREDI,15,18}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_SIGNES,MARDI,9,11}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,SAMEDI,9,11}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,JEUDI,8,10}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,MARDI,14,18}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,MARDI,14,17}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,MARDI,8,12}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_CODAGE,SAMEDI,10,12}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,SAMEDI,16,18}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,VENDREDI,15,17}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,VENDREDI,16,18}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,MARDI,13,16}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,SAMEDI,9,11}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,MARDI,10,12}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,LUNDI,8,12}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MARDI,13,19}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,LUNDI,9,12}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,JEUDI,13,18}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,LUNDI,14,19}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,VENDREDI,16,18}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,MARDI,9,11}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,MARDI,10,12}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MERCREDI,8,12}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,LUNDI,10,12}
    }
};         
