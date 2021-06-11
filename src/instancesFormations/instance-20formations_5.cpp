#include "instance-20formations_5.h"
                
/* competences des interfaces en SIGNES et CODAGE*/
int competences_interfaces[NBR_INTERFACES][2]={
    {1,0}, /* compétence en langages des SIGNES mais pas en CODAGE LPC */
    {0,1}, /* pas de compétence en langages des SIGNES mais compétence en CODAGE LPC */
    {0,1},
    {1,0},
    {1,0},
    {0,1}
};
                
/* specialite des interfaces */
int specialite_interfaces[NBR_INTERFACES][NBR_SPECIALITES]={
    {0,1,0,0,0},
    {0,0,0,0,0},
    {1,0,1,0,0},
    {0,0,1,1,0},
    {1,0,0,1,1},
    {0,1,0,1,0}
};
                  
/* coordonnées des centres de formation, des interfaces et des apprenants */
float coord[NBR_CENTRES_FORMATION+1][2]={
                  
    /* Les interfaces se rendent du centre SESSAD à l'école de formation */
    {53,130}, /* centre 0 */
                  
    /* Centres de formation */
    {123,41}, /* ecole formation SPECIALITE_MENUISERIE */
    {20,109}, /* ecole formation SPECIALITE_ELECTRICITE */
    {95,198}, /* ecole formation SPECIALITE_MECANIQUE */
    {23,70}, /* ecole formation SPECIALITE_INFORMATIQUE */
    {195,196} /* ecole formation SPECIALITE_CUISINE */
};

/* formation : id formation, specialite ou centre de formation, competence, horaire debut formation, horaire fin formation */
int formation[NBR_APPRENANTS][NBR_FORMATIONS_APPRENANT][6]={
    {
       {0,SPECIALITE_MENUISERIE,COMPETENCE_SIGNES,MERCREDI,13,18}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_CODAGE,JEUDI,14,17}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_CODAGE,VENDREDI,14,18}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,LUNDI,14,17}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_CODAGE,SAMEDI,8,11}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,MERCREDI,10,12}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,MERCREDI,16,19}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_SIGNES,JEUDI,15,17}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_CODAGE,VENDREDI,13,15}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_CODAGE,SAMEDI,15,19}
    },
    {  
        {0,SPECIALITE_CUISINE,COMPETENCE_SIGNES,MARDI,10,12}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,SAMEDI,13,15}
    },
    {  
        {0,SPECIALITE_MENUISERIE,COMPETENCE_CODAGE,VENDREDI,10,12}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_CODAGE,LUNDI,14,17}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,MERCREDI,14,19}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,MERCREDI,9,12}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_SIGNES,VENDREDI,8,11}
    },
    {  
        {0,SPECIALITE_INFORMATIQUE,COMPETENCE_SIGNES,VENDREDI,10,12}
    },
    {  
        {0,SPECIALITE_ELECTRICITE,COMPETENCE_CODAGE,SAMEDI,9,11}
    },
    {  
        {0,SPECIALITE_MECANIQUE,COMPETENCE_CODAGE,JEUDI,14,19}
    }
};         
