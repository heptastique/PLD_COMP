#pragma once


#include "Initialisation.h"
#include "Variable.h"
#include <list>

class InitialisationTab : public Instruction {

public:

    void print(std::ostream& stream) const;

    friend std::ostream& operator<< (std::ostream& stream, const InitialisationTab& initialisationTab);

    void setSize(std::string size){
        this->size = size;
    }

    void setType(Type type){
        this->type = type;
    }

    InitialisationTab &operator=(const InitialisationTab &unInitialisationTab);

    InitialisationTab(Type type, std::string name, std::list<Variable*> variables);

    virtual ~InitialisationTab();

private:

    // There could be no size
    std::string size;
    std::list<Variable*> variables;
    std::string name;
    Type type;
};
