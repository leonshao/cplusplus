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
    string q1("When lilacs last in the dooryard bloom'd");
    string q2("The child is father of the man");

    string sentence;

    string subString = q2.substr(0, q2.find("father"));
    sentence.assign(subString);

    string::size_type pos;
    pos = q1.find("in");
    subString = q1.substr(pos, q1.find("bloom") - pos);
    sentence.append(subString);
    cout << sentence << endl;
}
