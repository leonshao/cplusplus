#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string input;
    vector<string> vec_str;

    while (cin >> input)
        vec_str.push_back(input);

    vector<string>::size_type i;
    for(i = 0; i != vec_str.size(); i++)
    {
        if (i % 8 == 0)
            cout << endl;

        string &str = vec_str[i];
        for (string::size_type j = 0; j != str.size(); j++)
            str[j] = toupper(str[j]);
        cout << vec_str[i] << " ";
    }
    cout << endl;

    return 0;
}
