#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::ifstream;
using std::istream_iterator;
using std::ostream_iterator;
using std::string;

int main()
{
    ifstream input("ostream_iterator.cpp");
    istream_iterator<string> in_iter(input), eof;
    ostream_iterator<string> out_iter(cout, " ");

    while (in_iter != eof)
        *out_iter++ = *in_iter++;

    return 0;
}
