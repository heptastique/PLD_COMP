#pragma once

#include "Instruction.h"
#include "Variable.h"
#include <list>

class AppelFunction : public Instruction{
public:
    friend std::ostream& operator<< (std::ostream& stream, const AppelFunction& appelFunction);

    void print(std::ostream& stream) const;

    AppelFunction &operator=(const AppelFunction &unAppelFunction);

    AppelFunction(const AppelFunction &unAppelFunction);

    AppelFunction(std::string name, std::list<Variable *> variables);

    virtual ~AppelFunction();

private:
    std::string name;
    std::list<Variable *> variables;
};
