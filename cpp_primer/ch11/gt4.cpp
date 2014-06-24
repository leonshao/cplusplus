#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::count_if;
using std::unique;

bool GT4(const string &s)
{
    return s.size() >= 4;
}

int main()
{
    vector<string> strVec;
    string word;

    while (cin >> word)
        strVec.push_back(word);

    vector<string>::size_type wc = count_if(strVec.begin(), strVec.end(), GT4);
    cout << wc << " words 4 characters or longer" << endl;

    sort(strVec.begin(), strVec.end());
    vector<string>::iterator end_unique = unique(strVec.begin(), strVec.end());
    vector<string>::iterator itr;
    for (itr = strVec.begin(); itr != end_unique; ++itr)
        cout << *itr << " ";
    cout << endl;

    return 0;
}
