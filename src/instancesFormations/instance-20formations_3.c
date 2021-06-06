#include "instance-20formations_3.h"
              
/* competences des interfaces en SIGNES et CODAGE*/
int competences_interfaces[NBR_INTERFACES][2]={
    {1,0}, /* compétence en langages des SIGNES mais pas en CODAGE LPC */
    {0,1}, /* pas de compétence en langages des SIGNES mais compétence en CODAGE LPC */
    {0,1},
    {1,0},
    {0,1},
    {0,1}
};

/* specialite des interfaces */
int specialite_interfaces[NBR_INTERFACES][NBR_SPECIALITES]={
    {0,0,0},
    {1,0,0},
    {0,0,1},
    {0,1,1},
    {0,0,0},
    {0,0,0}
};
                  
/* coordonnées des centres de formation, des interfaces et des apprenants */
float coord[NBR_CENTRES_FORMATION+1][2]={
                  
    /* Les interfaces se rendent du centre SESSAD à l'école de formation */
    {23,79}, /* centre 0 */
                  
    /* Centres de formation */
    {162,73}, /* ecole formation SPECIALITE_MENUISERIE */
    {92,160}, /* ecole formation SPECIALITE_ELECTRICITE */
    {40,179} /* ecole formation SPECIALITE_MECANIQUE */
};

/* formation : id formation, specialite ou centre de formation, competence, horaire debut formation, horaire fin formation */
int formation[NBR_APPRENANTS][NBR_FORMATIONS_APPRENANT][6]={
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,JEUDI,8,10}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,SAMEDI,10,12}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,MARDI,16,18}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,MERCREDI,13,16}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,MARDI,15,19}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,SAMEDI,16,18}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,MERCREDI,14,17}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,LUNDI,9,12}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,VENDREDI,9,11}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,MERCREDI,16,19}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MARDI,10,12}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,MARDI,15,19}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,MARDI,16,18}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,LUNDI,8,11}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,MARDI,15,17}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,MARDI,13,17}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,MERCREDI,8,11}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,MARDI,8,11}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_SIGNES,MERCREDI,13,19}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,LUNDI,13,18}
    }
}; 
