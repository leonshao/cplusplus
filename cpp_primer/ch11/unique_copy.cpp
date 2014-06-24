#include <algorithm>
#include <iterator>
#include <vector>
#include <list>
#include <iostream>
#include <string>
using std::vector;
using std::list;
using std::cout;
using std::cin;
using std::endl;
using std::unique_copy;
using std::sort;
using std::back_inserter;
using std::front_inserter;
using std::inserter;
using std::string;

void print_vector(vector<string> &iVec)
{
    vector<string>::const_iterator itr;
    for (itr = iVec.begin(); itr != iVec.end(); ++itr)
        cout << *itr << " ";
    cout << endl;
}

int main()
{
    list<string> strList;
    string word;

    while (cin >> word)
        strList.push_back(word);

    // sort(strList.begin(), strList.end());

    vector<string> strVec;
    unique_copy(strList.begin(), strList.end(), inserter(strVec, strVec.begin()));
    print_vector(strVec);

    vector<string> strVecBack;
    unique_copy(strList.begin(), strList.end(), back_inserter(strVecBack));
    print_vector(strVecBack);

    return 0;
}
