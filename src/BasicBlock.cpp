using namespace std;

# include "BasicBlock.h"
# include <iostream>

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
