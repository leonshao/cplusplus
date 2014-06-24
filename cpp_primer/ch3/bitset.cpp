#include <iostream>
#include <string>
#include <bitset>
#include <cstddef>

using std::cin;
using std::cout;
using std::endl;
using std::bitset;

int main()
{
    bitset<32> bitvec;

    for(size_t i = 0; i < bitvec.size(); i++)
    {
        switch(i)
        {
            case 1:
            case 2:
            case 3:
            case 5:
            case 8:
            case 13:
            case 21: bitvec[i] = 1;
        }
    }

    cout << bitvec << endl;

    return 0;
}
