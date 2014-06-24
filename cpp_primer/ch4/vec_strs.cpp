#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
    string s;
    vector<string> svec;

    while (cin >> s)
        svec.push_back(s);

    vector<string>::size_type vec_size = svec.size();

    char **p = new char *[vec_size];
    for (vector<string>::size_type i = 0; i < vec_size; i++) {
        p[i] = new char[svec[i].size() + 1];
        strcpy(p[i], svec[i].c_str());
    }

    for (char **q = p; q != p + vec_size; q++)
        cout << *q << " ";

    cout << endl;

    for (char **q = p; q != p + vec_size; q++) {
        cout << "deleting " << q << endl;
        delete [] *q;
        cout << q << " deleted" << endl;
        *q = NULL;
    }

    delete [] p;

    return 0;
}
