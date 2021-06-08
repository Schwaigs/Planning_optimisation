#include <list>
#include "chromosome.h"

using namespace std;

// initialisation des param�tres d'un chromosome
chromosome::chromosome(int tc)
{
	//au depart chacune des interface est encore plainement disponible, elle a donc 35h restantes

	tempsRestantIntervenants =  new int[NBR_INTERFACES];
	for(int i=0; i<NBR_INTERFACES; i++){
		tempsRestantIntervenants[i] = 35;
	}

	taille = tc;
	// un chromosome est compos� de 'taille' g�nes,
	// les g�nes sont carat�ris� par un entier compris entre 0 et 'taille-1'
	genes = new int[taille];
	//initialisation a -1 partout car 0 est une valeur valide qu'il faut différencier
	for(int i=0; i<taille; i++){
		genes[i] = -1;
	}

	//on parcourt la liste des apprenants pour leur attribuer à chacun une interface
	for(int i=0; i<taille; i++){

		//on recupère l'identifiant de l'apprenant et le numéro du cours
		int idApprenant = i / NBR_FORMATIONS_APPRENANT;
		int idCours = i % NBR_FORMATIONS_APPRENANT;

		//on stocke les interfaces possedants la bonne competence
		int competenceApprenant = formation[idApprenant][idCours][2];
		list<int> interfaceMatch;

		for(int j=0; j<NBR_INTERFACES; j++){
			bool checkCompetenceIntervenant = competences_interfaces[j][competenceApprenant];
			if(checkCompetenceIntervenant){
				interfaceMatch.push_back(j);
			}
		}

		//on verifie que ces interfaces sont bien disponibles pour ce creneau de formation
		for(list<int>::iterator it = interfaceMatch.begin(); it != interfaceMatch.end(); it++){
			int idIntervenant = *it;
			bool dispo = interfaceDispo(idIntervenant, idApprenant, idCours);

			//si l'interface est toujours disponible, on verifie qu'elle ne depassera pas les 35h en lui ajoutant le creneau courant
			if(dispo){
				if( (tempsRestantIntervenants[idIntervenant] - (formation[idApprenant][idCours][5]-formation[idApprenant][idCours][4])) < 0){
					dispo = false;
				}
			}

			//si l'interface n'est pas disponible on la retire de la liste
			if(!dispo){
				it = interfaceMatch.erase(it);
				--it;
			}

		}

		//on choisi enfin aléatoirement l'interface qui sera affectée pour le creneau parmis celles disponibles
		//si aucune interface ne convient, alors on doit recommencer à chercher une solution depuis le début
		if(interfaceMatch.empty()){
			i = 0;
		}
		else{
			int a = Random::aleatoire(interfaceMatch.size());

			//on parcours la liste des interfaces disponibles
			list<int>::iterator it = interfaceMatch.begin();
			for (int j=0; j<a; j++){
				it++;
			}
			genes[i] = *it;

			//on met à jour son nombre d'heure restant
			tempsRestantIntervenants[genes[i]] -= formation[idApprenant][idCours][5]-formation[idApprenant][idCours][4];
		}

	}
}

// destruction de l'objet 'chromosome'
chromosome::~chromosome()
{
	delete genes;
	delete tempsRestantIntervenants;
}

//vérifie la disponibilité d'une interface pour un creaneau de formation
bool chromosome::interfaceDispo(int idIntervenant, int idApprenant, int idCours){

	bool dispo = true;

	int incideCreneauCourant = idApprenant * NBR_FORMATIONS_APPRENANT + idCours;
	int centreCreneauCourant = formation[idApprenant][idCours][1];
	int jCreneauCourant = formation[idApprenant][idCours][3];
	int hDebutCreneauCourant = formation[idApprenant][idCours][4];
	int hFinCreneauCourant = formation[idApprenant][idCours][5];

	//on parcours la solution pour trouver les creneaux de formation où l'interface est déjà affectée
	for(int i=0; dispo && i<taille; i++){

		//on recupère l'identifiant de l'apprenant et le numéro du cours où elle est déjà affectée
		int idApprenantAffecte = i / NBR_FORMATIONS_APPRENANT;
		int idCoursAffecte = i % NBR_FORMATIONS_APPRENANT;

		//on verfife la compatibilite des horaires

		//si l'interface est deja affectee a une formation ce jour là
		if(genes[i] != -1 && i != incideCreneauCourant && genes[i] == idIntervenant && formation[idApprenantAffecte][idCoursAffecte][3] == jCreneauCourant){
			//on verfife la compatibilite des horaires
			int centreCreneauAffecte = formation[idApprenantAffecte][idCoursAffecte][1];
			int hDebutCreneauAffecte = formation[idApprenantAffecte][idCoursAffecte][4];
			int hFinCreneauAffecte = formation[idApprenantAffecte][idCoursAffecte][5];

			if((hFinCreneauAffecte > hDebutCreneauCourant) && (hDebutCreneauAffecte < hFinCreneauCourant)){
				dispo = false;
			}

			//si le centre de formation est le même
			//l'heure de debut et l'heure de fin de deux creneaux qui se suivent peuvent être la même
			//sinon ce n'est pas possible car il ya le temps de trajet entre les deux centre
			else if( (centreCreneauAffecte != centreCreneauCourant) &&
				((hFinCreneauAffecte == hDebutCreneauCourant) || (hDebutCreneauAffecte == hFinCreneauCourant)) ){
				dispo = false;
			}
		}
	}

	return dispo;
}

//vérifie la validité d'une solution
bool chromosome::valide(){

	bool valide = true;

	//on parcourt la liste des apprenants pour verifier que l'intervenant qui lui est affecté réponds aux critères de validité
	for(int i=0; valide && i<taille; i++){

		int idIntervenant = genes[i];
		//on recupère l'identifiant de l'apprenant et le numéro du cours
		int idApprenant = i / NBR_FORMATIONS_APPRENANT;
		int idCours = i % NBR_FORMATIONS_APPRENANT;

		//l'intervenant doit posseder la bonne compétence
		int competenceApprenant = formation[idApprenant][idCours][2];
		valide  = competences_interfaces[idIntervenant][competenceApprenant];

		//l'intervenant doit être disponible sur le creneau horaire de la formation
		valide = valide && interfaceDispo(idIntervenant, idApprenant, idCours);

		//l'intervenant ne doit pas depasser les 35h
		valide = valide && (tempsRestantIntervenants[idIntervenant] >= 0);
	}

	return valide;
}

// �valuation d'une solution : fonction qui calcule la fitness d'une solution
void chromosome::evaluer()
{
	//On créer un tableau de list
    list<int> tabList[NBR_INTERFACES];

	//l'indice du tableau est égal à l'identifant de l'intervenant
	//la list correspond aux différentes formations (dans l'ordre chronologiques de la semaine) auxquelles sont affectés les intervenants

	//On creer une variable représentant les spécilités non respectées
    int nbSpecNonRespectees = 0;

    int idIntervenant, idApprenantCourant, idFormationCourante;
    int jourCourant, heureCourante;
    int jourCours, heureCours;
    int speFormationCourante;

    //On parcours les genes du chromosomes, donc les différents créneaux de formations

    for(int i=0; i < taille; i++){
		//Pour chaque créneau de formation on recupère l'id de l'intervenant affectée, donc la valeur du gene
        idIntervenant = genes[i];
		//On recupère aussi l'id de l'apprenant ainsi que l'identifiant du cours à partir de l'indice du gene
        idFormationCourante = i%NBR_FORMATIONS_APPRENANT;
        idApprenantCourant = i/NBR_FORMATIONS_APPRENANT;

		//On recupère le jour et l'heure de début du créneau horaire (ce sera le créneau courant)
        jourCourant = formation[idApprenantCourant][idFormationCourante][3];
        heureCourante = formation[idApprenantCourant][idFormationCourante][4];
		//On parcours la list des formations auxquelles l'intervenant est affecté
        auto j = tabList[idIntervenant].begin();

        bool inList=false;
        if (tabList[idIntervenant].size()==0){
            tabList[idIntervenant].push_back(idApprenantCourant*NBR_FORMATIONS_APPRENANT + idFormationCourante);
        }else {
            for( j = tabList[idIntervenant].begin() ; j!=tabList[idIntervenant].end(); j++){
                inList=false;
                for (auto k =tabList[idIntervenant].begin(); k != tabList[idIntervenant].end(); k++ )
                {
                    if (*k%NBR_FORMATIONS_APPRENANT==idFormationCourante)
                    {
                        inList=true;
                    }

                }
                //Pour chaque formation on recupère son jour et son heure de début pour les comparer à ceux du créneau courant
                int idFormation = *j%NBR_FORMATIONS_APPRENANT;
                int idApprenant = *j/NBR_FORMATIONS_APPRENANT;

                //Si le jour est supérieur au jour courant
                if (formation[idApprenant][idFormation][3]>jourCourant && !inList) {
                    //Alors on sauvegarde l'identifiant formé de l'id de l'apprenant ainsi que du numéro du cours
                    // (même formule que dans la représentation de la solution) dans la list de l'intervenant à cette position
                    tabList[idIntervenant].insert(j, idApprenantCourant*NBR_FORMATIONS_APPRENANT + idFormationCourante);
                }else if(formation[idApprenant][idFormation][3]==jourCourant && formation[idApprenant][idFormation][4]>heureCourante&& !inList){
                //Sinon si le jour est le même on fait la même chose en comparant les horaire pour savoir si le creneau courant est plus tot dans la journée
                    tabList[idIntervenant].insert(j, idApprenantCourant*NBR_FORMATIONS_APPRENANT + idFormationCourante);
                }

                //Sinon rien (on passe à la prochaine formation stockée dans la list pour la comparer au créneau courant)
            }
        }
        if (j == tabList[idIntervenant].end())
        {
            inList=false;
            for (auto k =tabList[idIntervenant].begin(); k != tabList[idIntervenant].end(); k++ )
            {
                if (*k%NBR_FORMATIONS_APPRENANT==idFormationCourante)
                {
                    inList=true;
                }

            }
            if (!inList)
            {
                tabList[idIntervenant].push_back(idApprenantCourant*NBR_FORMATIONS_APPRENANT + idFormationCourante);
            }

        }


		//On recupère la spécialite de le formation courante
        speFormationCourante=formation[idApprenantCourant][idFormationCourante][1];
		//On regarde si l'intervenant possède cette spécialité
        if (!(specialite_interfaces[idIntervenant][speFormationCourante]))
        {

		//Si non on incrémente la variable des specialités non satisfaites
            nbSpecNonRespectees++;
        }

    }

	//Une fois toutes les formations stockés dans l'ordre chronologique

	//On créer un tableau de float qui stocke la distance parcourue par chaque intervenant
	//l'indice est l'id de l'apprenant
	float tabDistances[NBR_INTERFACES];
    float distanceParcourue;
    int centrePrecedent=0;
	//On parcours le tableau de list, pour chaque intervenant on calcule la distance parcourue chaque jour
    for (int idIntervenant=0; idIntervenant <NBR_INTERFACES; idIntervenant++){
        distanceParcourue=0;
        for (int jour = 1; jour<=7; jour++){
            for (auto j = tabList[idIntervenant].begin() ; j!=tabList[idIntervenant].end(); j++){
                int idFormation = *j%NBR_FORMATIONS_APPRENANT;
                int idApprennant = *j/NBR_FORMATIONS_APPRENANT;
                if (jour == formation[idApprennant][idFormation][3])
                {
                    int centre = formation[idApprennant][idFormation][1];
                    if (j==tabList[idIntervenant].begin())
                    {
                    //la distance entre le SESSAD et le premier centre de formation ou il doit ce rendre dans la journée
                        distanceParcourue += abs(sqrt(pow(coord[centre+1][0] - coord[0][0],2) + pow(coord[centre+1][1] - coord[0][1],2)));
                    }else{

                        //Puis on calcul et additionne la distance entre chacun des centres de formation où il se rends dans la journée
                        distanceParcourue += abs(sqrt(pow(coord[centre+1][0] - coord[centrePrecedent+1][0],2) + pow(coord[centre+1][1] - coord[centrePrecedent+1][1],2)));
                    }
                centrePrecedent = centre;
                }
            }
		    //Enfin on additionne la distance entre le dernier centre de formation où il était et le SESSAD
            distanceParcourue+=abs(sqrt(pow(coord[0][0] - coord[centrePrecedent+1][0],2) + pow(coord[0][1] - coord[centrePrecedent+1][1],2)));
        }
         tabDistances[idIntervenant]=distanceParcourue;
    }

	//On calcul la moyenne et l'écart type des distances parcourues
    float totalDistances =0;
    for(int i =0; i<NBR_INTERFACES; i++){
        totalDistances+=tabDistances[i];
    }
    float moyenneDistances = totalDistances/NBR_INTERFACES;

    float diffMoyenne = 0;

    for(int i =0; i<NBR_INTERFACES; i++){
        diffMoyenne+=pow(tabDistances[i]-moyenneDistances, 2);
    }
    float ecartTypeDistances=sqrt(diffMoyenne/NBR_INTERFACES);

	//On calcul ensuite Fcorr à l'aide d'une double boucle
	//Pour chaque centre i (i allant de 0 à NBR_FORMATION inclu puisqu'il y a aussi le SESSAD)
    int fcorr=0;
    for (int i=0; i<=NBR_FORMATION; i++){
		//i est le centre de départ
        for(int j=0; j <= NBR_FORMATION; j++){
		//Pour chaque centre j (j allant de 0 à NBR_FORMATION inclu puisqu'il y a aussi le SESSAD)
			//On additionne à Fcorr la distance pour aller de i à j
            fcorr+= abs(sqrt(pow(coord[i][0] - coord[j][0],2) + pow(coord[i][1] - coord[j][1],2)));
        }
    }
    fcorr = (fcorr/2)/(NBR_FORMATION);
	//On divise Fcorr par 2 car on a compter les trajet ij mais aussi ji


	//On calcul l'evaluation de la solution
	//cout << "0.5 * (" << moyenneDistances << " + " << ecartTypeDistances << ") + 0.5 * " << fcorr << " * " << nbSpecNonRespectees << endl;
    fitness = 0.5 * (moyenneDistances + ecartTypeDistances) + 0.5 * fcorr * nbSpecNonRespectees;
}


// copie les genes d'un chromosome. la fitness n'est pas reprise
void chromosome::copier(chromosome* source)
{
	for(int i=0; i<taille; i++)
		genes[i] = source->genes[i];
}

//mélange aléatoire des valeurs d'un tableau passé en paramètre
void chromosome::shuffle(int *array, size_t n) {
	if (n > 1) {
		size_t i;
		for (i = 0; i < n - 1; i++)
		{
			size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
			int t = array[j];
			array[j] = array[i];
			array[i] = t;
		}
  	}
}

//mélange aléatoire des gènes situés entre deux points du chromosome
void chromosome::melange_alea_genes() {
	//Sélection aléatoire du point de départ
	int depart = Random::aleatoire(taille);
	int arrive;
	//Sélection aléatoire de la direction dans laquelle on se dirige: 0 = gauche ; 1 = droite
	int direction = Random::aleatoire(2);
	//Sélection aléatoire de la distance correspondant au nombre de gènes a modifier : compris entre 3 et 5
	int distance = Random::aleatoire_min_max(3, 6);

	//On détermine le point d'arrivée en fonction de la direction
	//Si on dépasse les limites du tableau, on ajuste les points de départ et d'arrivée de sorte à rester dans les limites du tableau
	if(direction == 0) {
		int tmp = depart;
		if((depart - distance) < 0) {
			distance = depart + 1;
			depart = 0;
		}
		else {
			depart = (depart - distance) + 1;
		}
		arrive = tmp + 1;
	}
	else {
		if((depart + distance) > taille) {
			distance = taille - depart;
			arrive = taille;
		}
		else {
			arrive = (depart + distance);
		}
	}

	//On récupère les gènes situés entre le point de départ et d'arrivée et on les stocke dans un tableau à part
	int* tab = (int*) malloc(distance * sizeof(int));
	int cpt = 0;
	for(int i = depart; i < arrive; i++) {
		tab[cpt] = genes[i];
		cpt++;
	}
	//On mélange ce tableau pour changer la position des gènes de manière aléatoire
	shuffle(tab, distance);
	//On affecte les gènes déplacés dans le chromosome à la place des anciens gènes
	cpt = 0;
	for(int i = depart; i < arrive; i++) {
		genes[i] = tab[cpt];
		cpt++;
	}
	free(tab);
}

//met à jour le tableau de temps de travail des interface suite à un changement dans les genes
void chromosome::majTempsTravailInterface(){

	//Au depart chacune des interface est encore plainement disponible, elle a donc 35h restantes
	for(int i=0; i<NBR_INTERFACES; i++){
		tempsRestantIntervenants[i] = 35;
	}

	//on parcourt la liste des formations auxquelles les interfaces sont affectées
	for(int i=0; i<taille; i++){

		//on recupère l'identifiant de l'apprenant et le numéro du cours
		int idApprenant = i / NBR_FORMATIONS_APPRENANT;
		int idCours = i % NBR_FORMATIONS_APPRENANT;

		//on met à jour le nombre d'heure restant de l'interface
		tempsRestantIntervenants[genes[i]] -= formation[idApprenant][idCours][5]-formation[idApprenant][idCours][4];
	}
}

// affichage des param�tre d'un chromosome
void chromosome::afficher()
{
	cout << genes[0];
	for(int i=1;i<taille;i++)
		cout << "-" << genes[i];
	cout << "" << endl;
	cout << " => fitness = " << fitness << endl;
}

bool chromosome::identique(chromosome* chro)
{
	for(int i=1; i<taille; i++)
		if (chro->genes [i] != this->genes[i])
			return false;
	return true;
}
