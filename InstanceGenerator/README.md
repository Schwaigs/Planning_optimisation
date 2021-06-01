% README.md
% Olivier Grunder
% 30/4/2021

L'objet du programme `InstanceGenerator` est de pouvoir générer des instances aléatoires pour le problème d'affectation.

Les 2 principaux paramètres d'entrée sont les suivants :

  - le nombre d'apprenants : `NBR_APPRENANTS`
  - le nombre de centres de formation : `NBR_CENTRES_FORMATION`

La compilation du programme peut se faire en ligne de commande avec :
~~~~bash
  javac -d ./bin src/instancegenerator/InstanceGenerator.java
~~~~

L'exécution du programme se fait par la ligne de commande :
~~~~bash
  java -cp ./bin instancegenerator/InstanceGenerator
~~~~

Le résultat du programme est la production d'un programme C contenant les différents paramètres d'une instance du problème. Si le nombre d'apprenants est 20, le nom du fichier sera : `instance-20formations.c`. Attention, si ce fichier existe déjà il sera écrasé. 
