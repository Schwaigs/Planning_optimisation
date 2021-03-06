# Planning optimisation

## I - Presentation du projet

Ce dépôt contient un projet réalisé dans la cadre du cours d'optimisation et recherche opérationnelle de l'UTBM. Le but est de développer une méthode de résolution, pour affecter le plus efficacement possible, des intervenants d'un SESSAD (centre proposant des Services d'accompagnement d'Education Spécialisée A Domicile) à des apprenants en situations handicap visuel ou auditif, afin de les aider lors de leur formation.

Dieses Repository enthält ein Projekt, das im Rahmen des Kurses für Optimierung und Operationsforschung des UTBM realisiert wurde. Das Ziel war die Entwicklung einer Auflösungsmethode, um Lernenden mit Seh- oder Hörbehinderungen möglichst effizient einen Helfer zuzuordnen, um sie bei ihrer Ausbildung zu unterstützen.

This repository contains a project realized for the optimisation and operational research of the UTBM. The purpose is to develop a method for assigning support workers to learners with visual or hearing disabilities in the most effective way possible, in order to assist them in their training.

## II - Utilisation

### Environement Linux
Pour compiler le projet dans un environnement linux, dans un terminal, placez vous à la racine du projet. Ensuite lancer le script `build` à l'aide de la commande suivante :

    ./build

Une fois le projet complilé, il vous suffit de le lancer à l'aide du script `run`. Il est possible d'executer ce sript de deux manière différentes. Premièrement simplement sans arguments, les paramètres auront alors leurs valeurs par défaut (une taille de population égale au nombre de créneaux de formation, un taux de croisement de 0.5 et un taux de mutation de 0.01). La commande à executée dans ce cas de figure est la suivante :

    ./run

L'autre possibilité est de passer 3 arguments, les paramètres prendrons alors ces valeurs. Le script s'execute alors comme suit :

    ./run <taille_population> <taux_croisement> <taux_mutation>

En cas de problèmes de droits avec l'un des scripts faites les commandes :

    chmod u+x ./build
    chmod u+x ./run

### Environement Windows
Pour compiler le projet dans un environnement Windows, dans l'invite de commande cmd, placez vous à la racine du projet. Ensuite lancer le script `buildWindows` à l'aide de la commande suivante :

    buildWindows.bat

Une fois le projet complilé, il vous suffit de le lancer à l'aide du script `runWindows`. Il est possible d'executer ce sript de deux manière différentes. Premièrement simplement sans arguments, les paramètres auront alors leurs valeurs par défaut (une taille de population égale au nombre de créneaux de formation, un taux de croisement de 0.5 et un taux de mutation de 0.01). La commande à executée dans ce cas de figure est la suivante :

    runWindows.bat

L'autre possibilité est de passer 3 arguments, les paramètres prendrons alors ces valeurs. Le script s'execute alors comme suit :

    runWindows.bat <taille_population> <taux_croisement> <taux_mutation>

En cas de problèmes de droits, ralancer l'invite de commande en l'executant en tant qu'administrateur.

## III - Changement du fichier d'instances

Le fichier d'instance utilisé par défaut est le fichier `instance-80formation_5`. Celui-ci comprends 80 apprenants suivant tous une seule formation par semaines, les formations proposées étant de 5 spécialitées différentes. 

Pour utiliser un autre fichier d'instance, dans le cas où celui-ci est déjà présent dans le dossier src/instancesFormations. Puisque nous utilisons directements les fichiers .cpp et .h, il faut modifier l'instruction `#include` qui se trouve dans les fichiers `AlgoGenetic.h`, `Chromosome.h` et `main.cpp`, en la remplacant par le nom du nouveau fichier d'instance à utiliser. Il faut faire de même à la ligne 39 du `makefile`

Dans le cas d'un fichier qui n'est pas proposé dans le dossier src/instancesFormations. Il faut au préalable utiliser le générateur d'instance pour gérerer un premier fichier C. Ensuite il faudra extraire le contenu de ce fichier pour créer les fichiers .cpp et .h à placé dans le dossier src/instancesFormations en respectant la même nomenclature que les fichiers déjà présents. Enfin, faire la même manipulation de changement des *include* et du *makefile* expliquée dans le paragraphe précédent. 
