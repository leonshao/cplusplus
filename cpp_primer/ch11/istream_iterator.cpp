#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::istream_iterator;
using std::ostream_iterator;
using std::vector;
using std::unique_copy;

int main()
{
    istream_iterator<int> in_iter(cin), eof;
    vector<int> vec(in_iter, eof);
    ostream_iterator<int> out_iter(cout, " ");

    sort(vec.begin(), vec.end());
    unique_copy(vec.begin(), vec.end(), out_iter);

    return 0;
}
