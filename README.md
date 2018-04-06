# PLD_COMP
[![Build Status](https://travis-ci.org/heptastique/PLD_COMP.svg?branch=master)](https://travis-ci.org/heptastique/PLD_COMP)

## From C to x86

### Le front end supporte
- Programme avec plusieurs déclarations et plusieurs fonctions.
    - Include.
    - Putchar().
    - Variables globales.
    - Types de variables : int32_t, int64_t et char.
    - Fonction avec plusieurs paramètres.
    - Instructions : 
        - multiples : déclarations, affectations, initialisations (avec prise en charge des tableaux); expression,
        - appel fonction, retour fonction,
        - if-else,  while.
    - Opérations présentes dans les fichiers de test.
        - binaires, unaires et les post-pré/incrémentations-décrémentations
    - Expression pouvant être :
        - (expr), variable, appelfonction, operationunaire expr, expr operationbinaire expr. 
        
### Le backend implemente:

- Compiler un programme qui fait un putchar() (5.3)
- Compiler l’affectation vers une variable (5.4)
- Compiler des expressions (5.5) (- comma et {in/de}crémentations)
- Compiler le if ... else (5.6)
- Compiler les boucles while (5.7)
- Retour de valeur (5.8)
- Compiler l’affectation à une lvalue quelconque (5.9)
- Compiler les appels de fonction ayant jusqu’à 6 arguments (5.11)
- Test sur des programmes complexes (5.13) (Factorielle)
- Compiler les appels de fonction ayant plus de 6 arguments (5.15) (A Valider)

### A completer sur le back

- Variables globales
- Gestion des erreurs
- BasicBlocks
- Optimisations
- Initialisation (Héritage)
- Opérateurs (comma et {in/de}crémentations)
- Déclaration hors des blocs principaux des fonctions (Parcours déclaration en amont)
- Returns multiples (Double épilogue) 
- Compiler des tableaux (5.10) (Accès Mémoire)
- Compiler les boucles for (5.12) (Temps)
- Gestion correcte des types (5.14) (Evaluation Taille)

## Linux installation

### Prerequisites
- Recent gcc, at least 5.x.x
- Install [CMake](https://cmake.org/download/) if not done.
- Install uuid if not done
```
$ sudo apt-get install uuid-dev 
```
- Install gflags if not done.
```
$ sudo apt-get install libgflags-dev
```
### Create the executable
- Run
```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
```

## Testing

- symbols-test tests and errors-test are in charge of testing front end functions
- asm-test is responsible for the ASM code generated by the back-end
- cli-test checks if the command line options are working properly
- exec-test checks tests the execution of the generated code
- Testing
```bash
$ cd tests
$ ./symbols-test.sh -v
$ ./asm-test.sh -v
$ ./errors-test.sh -v
$ ./cli-test.sh -v
$ ./exec-test.sh
```
## Using
- Usage:
```
app sourceFile [-o/-oout/-Sout] [targetFile]
# The default usage writes the asm to ./target.prog.s
./bin/app source.c
# use -o to generate an executable at ./target/prog.out
./bin/app source.c -o
# use -Sout to create the asm to the specified path
./bin/app source.c -Sout path/to/file.s
# use -oout to create the executable to the specified path
./bin.app source.c -oout path/to/exe.out
```
