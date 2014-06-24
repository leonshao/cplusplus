#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> ivec;
    cout << "ivec size: " << ivec.size()
         << ", capacity: " << ivec.capacity() << endl;

    for(int i=0; i<24; ++i)
        ivec.push_back(i);

    // ivec size: 24, capacity: 32
    cout << "ivec size: " << ivec.size()
         << ", capacity: " << ivec.capacity() << endl;

    ivec.reserve(50);

    // ivec size: 24, capacity: 50
    cout << "ivec size: " << ivec.size()
         << ", capacity: " << ivec.capacity() << endl;

    while(ivec.size() != ivec.capacity())
        ivec.push_back(0);

    // ivec size: 50, capacity: 50
    cout << "ivec size: " << ivec.size()
         << ", capacity: " << ivec.capacity() << endl;

    ivec.push_back(42);

    // ivec size: 51, capacity: 100
    cout << "ivec size: " << ivec.size()
         << ", capacity: " << ivec.capacity() << endl;

    return 0;
}
