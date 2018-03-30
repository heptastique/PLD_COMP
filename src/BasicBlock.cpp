# include "BasicBlock.h"

# include <string>
# include <vector>
# include <iostream>

using namespace std;

vector <IRInstr> BasicBlock::getIRInstrs() const
{
	return iRInstrs;
}

void BasicBlock::addFunctionDefinition(string functionName, int addressRangeSize)
{
	vector <string> params;

	params.push_back(functionName);
	params.push_back(to_string(addressRangeSize));

	IRInstr iRInstr(FUNCTION_DECLARATION, params);

	iRInstrs.push_back(iRInstr);
}

void BasicBlock::generateASM()
{
	#ifdef MAP
		cout << "Appel a la methode generateASM de <BasicBlock>" << endl;
	#endif
}

BasicBlock::BasicBlock(const BasicBlock &basicBlock)
{
	#ifdef MAP
		cout << "Appel au constructeur de copie de <BasicBlock>" << endl;
	#endif

	iRInstrs = basicBlock.getIRInstrs();
}

BasicBlock::BasicBlock()
{
	#ifdef MAP
		cout << "Appel au constructeur de <BasicBlock>" << endl;
	#endif
}

BasicBlock::~BasicBlock()
{
	#ifdef MAP
		cout << "Appel au destructeur de <BasicBlock>" << endl;
	#endif
}
