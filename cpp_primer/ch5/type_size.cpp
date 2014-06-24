#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    int x[10];
    int *ptr = x;
    cout << "char size: " << sizeof(char) << endl;
    cout << "int size: " << sizeof(int) << endl;
    cout << "long size: " << sizeof(long) << endl;
    cout << "short size: " << sizeof(short) << endl;
    cout << "float size: " << sizeof(float) << endl;
    cout << "double size: " << sizeof(double) << endl;
    cout << "bool size: " << sizeof(bool) << endl;
    cout << "ptr size: " << sizeof(ptr) << endl;
    cout << "x array size: " << sizeof(x) << endl;
    cout << sizeof(x)/sizeof(*x) << endl;
    cout << sizeof(ptr)/sizeof(*ptr) << endl;

    return 0;
}
