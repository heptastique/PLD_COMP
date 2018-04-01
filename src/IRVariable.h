
# include <string>

using namespace std;

class IRVariable
{
	public :

		IRVariable();
		IRVariable(string name, int offset);
		IRVariable(const IRVariable & iRVariable);
		~IRVariable();

	protected :

		string name;
		int offset; // position dans la pile par rapport à rsp
};
