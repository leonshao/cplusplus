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
    vector<int> vecInt;
    int i;

    while (cin >> i)
    {
        vecInt.push_back(i);
    }

    vector<int>::iterator itr;
    for (itr = vecInt.begin(); itr != vecInt.end(); ++itr)
    {
        int j = (*itr);
        (*itr) = (j % 2 ? j * 2 : j);
    }

    for (itr = vecInt.begin(); itr != vecInt.end(); ++itr)
        cout << *itr << " ";

    cout << endl;

    return 0;
}
