#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string sInput;
    vector<string *> vecPtrToStr;
    string * pStr;

    while (cin >> sInput)
    {
        pStr = new string(sInput);
        vecPtrToStr.push_back(pStr);
    }

    vector<string *>::iterator itr;
    for (itr = vecPtrToStr.begin(); itr != vecPtrToStr.end(); ++itr)
    {
        // 注意加括号(**itr), 点运算符"."优先级高于星运算符"*"
        // cout << "content:" << **itr << "\tsize:" << (**itr).size() << endl;
        cout << "content:" << **itr << "\tsize:" << (*itr)->size() << endl;
        delete *itr;
        *itr = NULL;
    }

    return 0;
}
