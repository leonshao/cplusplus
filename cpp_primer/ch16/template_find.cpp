#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::stringstream;

template <typename Itr, typename T> Itr myFind(Itr first, Itr last, const T& val)
{
    while(first != last)
    {
        if(*first == val) return first;
        ++first;
    }
    return last;
}

int main()
{
    vector<int> vecInt;
    int i;
    for(i = 0; i < 10; ++i)
        vecInt.push_back(i);

    int val = 11;
    vector<int>::iterator itr = myFind(vecInt.begin(), vecInt.end(), val);
    cout << "myFind " << val << " from vecInt: ";
    if(itr != vecInt.end())
        cout << *itr << endl;
    else
        cout << "not found!" << endl;

    vector<string> vecStr;
    for(i = 0; i < 10; ++i)
    {
        stringstream ss;
        ss << "str" << i;
        vecStr.push_back(ss.str());
    }

    vector<string>::iterator itrStr = myFind(vecStr.begin(), vecStr.end(), string("str3"));

    cout << "myFind str3 from vecStr: " << *itrStr << endl;

    return 0;
}
