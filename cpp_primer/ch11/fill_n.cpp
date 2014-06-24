#include <algorithm>
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;
using std::fill_n;

int main()
{
    vector<int> iVec;
    for (int i = 0; i < 10; ++i)
        iVec.push_back(i);

    cout << "original: ";
    vector<int>::iterator itr;
    for (itr = iVec.begin(); itr != iVec.end(); ++itr)
        cout << *itr << " ";
    cout << endl;

    cout << "after fill_n: ";
    fill_n(iVec.begin(), iVec.size(), 0);
    for (itr = iVec.begin(); itr != iVec.end(); ++itr)
        cout << *itr << " ";
    cout << endl;

    return 0;
}
