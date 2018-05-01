# Codes d'erreur

## Usage 

### Prototype
```cpp
static void ThrowError(int code, string name);
```

### Example
```cpp
#include "ErrorHandling.h"

ErrorHandling::ThrowError(101, "nombre");
```

Output :
```
Erreur 101 : Déclaration de variable nombre déjà existante
```

## Error codes

### Semantic errors
|Code|Description|
|------|------------|
101|Déclaration de la variable nomdelavariable déjà existante dans le bloc de la fonction
102|Déclaration de la variable nomdelavariable déjà définie en paramètre de la fonction
103|Déclaration de la variable nomdelavariable déjà définie globalement
104|Utilisation d'une variable non déclarée : nomdelavariable
105|La fonction nomdelafonction existe déjà
106|La fonction nomdelafonction n'existe pas

### Lex errors
|Code|Description|
|------|------------|
201|Caractère invalide

### Syntax errors
|Code|Description|
|------|------------|
301|Deux opérateurs suivis
302|Deux opérandes
303|Missing semicolon
304|Missing parenthesis
305|Too many closing parenthesis

# Codes warning

## Usage 

### Prototype
```cpp
static void ThrowWarning(int code, string name);
```

### Example
```cpp
#include "WarningHandling.h"

WarningHandling::ThrowWarning(101, "nombre");
```

Output :
```
Warning 110 : La fonction nombre n'est pas utilisée
```


## Warning codes

### Semantic warnings
|Code|Description|
|------|------------|
110|La fonction nomdelafonction  n'est pas utilisée
111|La variable local nomdelavariable n'est pas utilisée
112|La parametre nomdelavariable n'est pas utilisée
113|La variable global nomdelavariable n'est pas utilisée

