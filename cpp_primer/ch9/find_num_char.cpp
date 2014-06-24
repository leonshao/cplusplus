#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main()
{
    string str = "ab2c3d7R4E6";
    string number = "0123456789";
    string::size_type pos = 0;

    while((pos = str.find_first_of(number, pos)) != string::npos)
    {
        cout << str[pos] << ", ";
        ++pos;
    }
    cout << endl;

    pos = 0;
    while((pos = str.find_first_not_of(number, pos)) != string::npos)
    {
        cout << str[pos] << ", ";
        ++pos;
    }
    cout << endl;
}
