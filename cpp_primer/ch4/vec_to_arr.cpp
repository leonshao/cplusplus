#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
    string s;
    cin >> s;
    string::size_type s_size = s.size();
    char *p = new char[s_size + 1];

    strcpy(p, s.c_str());

    cout << p << endl;
    delete [] p;

    return 0;
}
