# include "IRVariable.h"

IRVariable::IRVariable()
{

}

IRVariable::IRVariable(string name)
{
	this->name = name;
}

IRVariable::IRVariable(const IRVariable & iRVariable)
{
	name = iRVariable.name;
}

IRVariable::~IRVariable()
{

}



