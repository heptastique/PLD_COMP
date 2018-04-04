#include "IRVariable.h"

int IRVariable::getOffset()
{
    return offset;
}

IRVariable::IRVariable()
{
    //
}

IRVariable::IRVariable(string name, int offset)
{
    this->name = name;
    this->offset = offset;
}

IRVariable::IRVariable(const IRVariable & iRVariable)
{
    name = iRVariable.name;
    offset = iRVariable.offset;
}

IRVariable::~IRVariable()
{
    //
}
