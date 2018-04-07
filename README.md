# PLD_COMP
[![Build Status](https://travis-ci.org/heptastique/PLD_COMP.svg?branch=master)](https://travis-ci.org/heptastique/PLD_COMP)

--------------------
## :loudspeaker: Note importante pour les correcteurs

Le projet se poursuit après la date de rendu du projet uniquement par plaisir. Un git tag `v1.0.0` a été créé marquant le rendu du projet, avant le vendredi 6 avril 20h.

Vous pouvez accéder à cette version [ici](https://github.com/heptastique/PLD_COMP/releases/tag/v1.0.0), en téléchargeant un dossier compressé, ou en clonant le dépôt et en accédant à cette release avec

``` bash
$ git checkout v1.0.0
```

Bien que la création de la release est postérieure à la date limite, il est possible de s'assurer de la date du dernier commit avec `git log`

--------------------

## Usage
``` bash
$ ./bin/app source.c [-o/-oout/-Sout] [source.c]

# Par défaut, génère uniquement l'assembleur dans le chemin ./target.prog.s
$ ./bin/app source.c

# -o génère l'exécutable dans le chemin ./target/prog.out
$ ./bin/app source.c -o

# -Sout pour choisir l'emplacement du fichier assembleur généré
$ ./bin/app source.c -Sout path/to/file.s

# -oout pour choisir l'emplacement de l'exécutable généré
$ ./bin.app source.c -oout path/to/exe.out
```

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
Tous les tests sont dans le dossier `tests`, et doivent être exécutés depuis ce dossier

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
$ ./exec-test.sh -v
```

## Fonctionnalités

### Front-end

#### :white_check_mark: Fonctionnel
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

#### :x: Non implémenté
- `for`
- Opérateur comma `,`

### Back-end

#### :white_check_mark: Fonctionnel

- **5.3** : Compiler un programme qui fait un `putchar()`
- **5.4** : Compiler l’affectation vers une variable
- **5.5** : Compiler des expressions (- comma et {in/de}crémentations)
- **5.6** : Compiler le `if ... else`
- **5.7** : Compiler les boucles `while`
- **5.8** : Retour de valeur
- **5.9** : Compiler l’affectation à une `lvalue` quelconque
- **5.11** : Compiler les appels de fonction ayant jusqu’à 6 arguments
- **5.13** : Test sur des programmes complexes (Factorielle)
- **5.15** : Compiler les appels de fonction ayant plus de 6 arguments

#### :x: Non implémenté

- Variables globales
- Gestion des erreurs
- BasicBlocks
- Optimisations
- Initialisation (Héritage)
- Opérateurs (comma et {in/de}crémentations)
- Déclaration hors des blocs principaux des fonctions (Parcours déclaration en amont)
- Returns multiples (Double épilogue) _Retours fonctionnels sur la branche `FixReturn`, mais les tests ne passent pas, car l'épilogue des fonctions peut être généré 2 fois, mais ne perturbe pas l'exécution du programme_
- **5.10** : Compiler des tableaux (Accès Mémoire)
- **5.12** : Compiler les boucles for (Temps)
- **5.14** : Gestion correcte des types (Evaluation Taille)
