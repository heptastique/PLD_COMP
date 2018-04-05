
#include <string>

using namespace std;

class IRVariable
{
    public:
        int getOffset();

        void setName(std::string name){
            this->name = name;
        }

        void setValue(std::string value){
          this->value = value;
        };

        std::string getValue(){
          return this->value;
        };

        IRVariable();
        IRVariable(string name, int offset);
        IRVariable(const IRVariable & iRVariable);
        ~IRVariable();

    protected:
        string name;
        int offset; // position dans la pile par rapport à rsp
        std::string value;
};
