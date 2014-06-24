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
    vector<int> vec = vector<int>(10, 10);
    vector<int>::iterator itr;

    for(itr = vec.begin(); itr != vec.end(); itr++)
    {
        *itr *= 2;
        cout << *itr << " ";
    }

    cout << endl;
    return 0;
}
