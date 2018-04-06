# PLD_COMP
[![Build Status](https://travis-ci.org/heptastique/PLD_COMP.svg?branch=master)](https://travis-ci.org/heptastique/PLD_COMP)

## Front-end

### Fonctionnel
- Programme avec plusieurs déclarations et plusieurs fonctions
- `Include`
- `Putchar()`
- Variables globales
- Types de variables : `int32_t`, `int64_t` et `char`
- Fonction avec plusieurs paramètres
- Instructions : 
    - multiples : déclarations, affectations, initialisations (avec prise en charge des tableaux); expression
    - appel fonction, retour fonction
    - `if-else`, `while`
- Opérations présentes dans les fichiers de test.
    - binaires, unaires et les post-pré/incrémentations-décrémentations
- Expressions pouvant être :
    - (expr), variable, appelfonction, operationunaire expr, expr operationbinaire expr. 

### Non implémenté
- `for`
- Opérateur comma `,`

## Back-end

### Fonctionnel

- Compiler un programme qui fait un `putchar()` **(5.3)**
- Compiler l’affectation vers une variable **(5.4)**
- Compiler des expressions **(5.5)** (- comma et {in/de}crémentations)
- Compiler le `if ... else` **(5.6)**
- Compiler les boucles `while` **(5.7)**
- Retour de valeur **(5.8)**
- Compiler l’affectation à une `lvalue` quelconque **(5.9)**
- Compiler les appels de fonction ayant jusqu’à 6 arguments **(5.11)**
- Test sur des programmes complexes (Factorielle) **(5.13)**
- Compiler les appels de fonction ayant plus de 6 arguments **(5.15)**

### Non implémenté

- Variables globales
- Gestion des erreurs
- BasicBlocks
- Optimisations
- Initialisation (Héritage)
- Opérateurs (comma et {in/de}crémentations)
- Déclaration hors des blocs principaux des fonctions (Parcours déclaration en amont)
- Returns multiples (Double épilogue) _Retours fonctionnels sur la branche `FixReturn`, mais les tests ne passent pas, car l'épilogue des fonctions peut être généré 2 fois, mais ne perturbe pas l'exécution du programme_
- Compiler des tableaux (5.10) (Accès Mémoire)
- Compiler les boucles for (5.12) (Temps)
- Gestion correcte des types (5.14) (Evaluation Taille)

## Installation sur Linux

### Pré requis
- gcc version 5.x.x ou plus récent
- [CMake](https://cmake.org/download/)
- Installer les dépendances suivantes
``` bash
$ sudo apt-get install uuid-dev 
$ sudo apt-get install libgflags-dev
```

### Compilation
``` bash
$ mkdir build
$ cd build
$ cmake ..
$ make
```

### Tests
Tous les tests sont dans le dossier `tests`, et doivent être exécutés depuis ce dosser

- `symbols-test.sh` et `errors-test` testent les fonctionnalités du front end
- `asm-test.sh` teste les fichiers assembleurs générés
- `cli-test.sh` teste le comportement des options du programme
- `exec-test.sh` teste l'exécution des programmes générés

``` bash
$ cd tests
$ ./symbols-test.sh -v
$ ./asm-test.sh -v
$ ./errors-test.sh -v
$ ./cli-test.sh -v
$ ./exec-test.sh
```
## Usage
``` bash
$ app source.c [-o/-oout/-Sout] [targetFile]

# Par défaut, génère uniquement l'assembleur dans le chemin ./target.prog.s
$ ./bin/app source.c

# -o génère l'exécutable dans le chemin ./target/prog.out
$ ./bin/app source.c -o

# -Sout pour choisir l'emplacement du fichier assembleur généré
$ ./bin/app source.c -Sout path/to/file.s

# -oout pour choisir l'emplacement de l'exécutable généré
$ ./bin.app source.c -oout path/to/exe.out
```
