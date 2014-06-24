#include <iostream>
#include <string>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::string;

char *pstr1 = "hello ";
char *pstr2 = "world";

int main()
{
    int size = strlen(pstr1) + strlen(pstr2) + 1;
    char *pstr_cat = new char[size]();

    strcat(pstr_cat, pstr1);
    strcat(pstr_cat, pstr2);

    cout << pstr_cat << endl;
    delete [] pstr_cat;

    string str1 = pstr1;
    string str2 = pstr2;
    string str_cat = str1 + str2;
    cout << str_cat << endl;

    return 0;
}
