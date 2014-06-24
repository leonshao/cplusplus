#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    string str = "strlen(NULL): ";
    char *p_str = NULL;
    str += p_str;
    cout << "strlen(NULL): " << strlen(NULL) << endl;
    return 0;
}
