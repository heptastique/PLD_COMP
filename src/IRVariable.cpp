# include "IRVariable.h"

IRVariable::IRVariable()
{

}

IRVariable::IRVariable(string name, int offset)
{
	this->name = name;
	this->offset = offset;
}

IRVariable::IRVariable(const IRVariable & iRVariable)
{
	name = iRVariable.name;
}

IRVariable::~IRVariable()
{

}



