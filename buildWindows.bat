cd src
g++    -c -o main.o main.cpp
g++    -c -o ae.o ae.cpp
g++    -c -o chromosome.o chromosome.cpp
g++    -c -o population.o population.cpp
gcc    -c -o instancesFormations/instance-80formations_5.o instancesFormations/instance-80formations_5.c
g++ -o main main.o ae.o chromosome.o population.o instancesFormations/instance-80formations_5.o -L/lib -L/usr/lib -L/usr/local/lib -lm