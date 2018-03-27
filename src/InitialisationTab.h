#pragma once


#include "Initialisation.h"
#include "Variable.h"
#include <list>

class InitialisationTab : public Initialisation {

public:

    void print(std::ostream& stream) const;

    friend std::ostream& operator<< (std::ostream& stream, const InitialisationTab& initialisationTab);

    void setIndex(std::string size){
        this->size = size;
    }

    InitialisationTab &operator=(const InitialisationTab &unInitialisationTab);

    InitialisationTab(Type type, Expression* expression, std::string name, std::list<Variable*> variables);

    virtual ~InitialisationTab();

private:

    // There could be no index
    std::string size;
    std::list<Variable*> variables;

};
