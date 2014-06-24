#include <algorithm>
#include <vector>
#include <iostream>
using std::vector;
using std::count;
using std::cout;
using std::endl;

int main()
{
    vector<int> iVec;
    for (int i = 0; i < 10; ++i)
        iVec.push_back(i);
    cout << "number 10 occurs " << count(iVec.begin(), iVec.end(), 10)
         << " times." << endl;
    return 0;
}
