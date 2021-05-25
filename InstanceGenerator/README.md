% README.md
% Olivier Grunder
% 30/4/2021

L'objet du programme `InstanceGenerator` est de pouvoir générer des
instances aléatoires pour le problème d'affectation.

Attention : il n'y a pas de test de cohérence entre 2 générations aléatoires de formations. Des erreurs peuvent survenir pour un même apprenant qui peut être associé à des formations avec des compétences différentes ou sur des créneaux qui se chevauchent. Pour cela, on considère qu'il n'y a qu'une seule formation par apprenant dans la semaine. Le nombre d'apprenants a été augmenté en conséquence pour avoir autant de formations dans cette configuration que dans la précédente.

Les 2 principaux paramètres d'entrée sont les suivants :

  - le nombre d'apprenants : `NBR_APPRENANTS`
  - le nombre de cours par semaine et par apprenant : `NBR_COURS_PAR_SEMAINE`
  - le nombre de centres de formation : `NBR_CENTRES_FORMATION`

La compilation du programme peut se faire par netbeans ou en ligne de commande
avec javac ou le script `./build`.

L'exécution du programme se fait par le script `./run` ou avec la ligne de
commande :

~~~~bash
    javac -d ./bin src/instancegenerator/InstanceGenerator.java
~~~~

Le résultat du programme est la production d'un programme C contenant les
différents paramètres d'une instance du problème. Si le nombre d'apprenants
est 20, le nom du fichier sera : `projet-ag41-20app.c`. Attention, si ce fichier
existe déjà il sera écrasé. 
