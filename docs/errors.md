# Codes d'erreur

## Usage 

### Prototype
```cpp
static void ThrowError(int code, int line);
```

### Example
```cpp
#include "ErrorHandling.h"

ErrorHandling::ThrowError(101, 2);
```

Output :
```
Ligne 2 - Erreur 101 : Déclaration de variable déjà existante
```

## Error codes

### Semantic errors
|Code|Description|
|------|------------|
101|Déclaration variable déjà existante
102|Redéclaration variable définie dans les paramètres de la fonction ou en variable globale
103|Redéclaration variable définie en variable globale
104|Utilisation d'une variable non déclarée

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
