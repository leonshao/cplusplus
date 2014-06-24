#include <numeric>
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;
using std::accumulate;

int main()
{
    vector<int> iVec;
    for (int i = 0; i < 10; ++i)
        iVec.push_back(i);

    int sum = accumulate(iVec.begin(), iVec.end(), 0);

    cout << "sum of 0-9 is: " << sum << endl;

    return 0;
}
