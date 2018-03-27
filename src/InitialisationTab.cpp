using namespace std;

#include "InitialisationTab.h"
#include <iostream>

InitialisationTab &InitialisationTab::operator=(const InitialisationTab &unInitialisationTab) {
}


InitialisationTab::InitialisationTab(const InitialisationTab &unInitialisationTab) {
#ifdef MAP
    cout << "Appel au constructeur de copie de <InitialisationTab>" << endl;
#endif
}


InitialisationTab::InitialisationTab() {
#ifdef MAP
    cout << "Appel au constructeur de <InitialisationTab>" << endl;
#endif
}


InitialisationTab::~InitialisationTab() {
#ifdef MAP
    cout << "Appel au destructeur de <InitialisationTab>" << endl;
#endif
}