using namespace std;

# include "ErrorHandling.h"
# include <iostream>

void ErrorHandling::ThrowError(int code, int line, string name)
{
    cout << "Ligne " << line << " - Erreur " << code << " : ";

    switch(code) {
        // Semantic errors
        case 101:
            cout << "Déclaration de la variable " << name << " déjà existante dans le bloc de la fonction" << endl;
            exit(101);
            break;
        case 102:
            cout << "Déclaration de la variable " << name << " déjà définie en paramètre de la fonction" << endl;
            exit(102);
            break;
        case 103:
            cout << "Déclaration de la variable " << name << " déjà définie globalement" << endl;
            exit(103);
            break;
        case 104:
            cout << "Utilisation d'une variable non déclarée : " << name << endl;
            exit(104);
            break;
        case 105:
            cout << "La fonction " << name << " existe déjà" << endl;
            exit(105);
            break;
        case 106:
            cout << "La fonction " << name << " n'existe pas" << endl;
            exit(106);
            break;

        // Lex errors
        case 201:
            cout << "Caractère invalide rencontré" << endl;
            exit(201);
            break;

        // Syntax errors:
        case 301:
            cout << "Deux opérateurs suivis recontrés" << endl;
            exit(301);
            break;
        case 302:
            cout << "Deux opérandes suivies rencontrées" << endl;
            exit(302);
            break;
        case 303:
            cout << "Absence de point-virgule en fin de ligne" << endl;
            exit(303);
            break;
        case 304:
            cout << "Parenthèse attendue" << endl;
            exit(304);
            break;
        case 305:
            cout << "Trop de parenthèses fermantes" << endl;
            exit(305);
            break;
    }

    cout << "\n" << endl;

    exit(code);
}
