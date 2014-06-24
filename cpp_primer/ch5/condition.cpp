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
    int i, j;
    cin >> i >> j;
    cout << (i < j ? i : j) << endl;
    return 0;
}
