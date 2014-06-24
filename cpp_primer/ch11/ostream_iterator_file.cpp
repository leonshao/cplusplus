#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
using std::cin;
using std::cout;
using std::ofstream;
using std::istream_iterator;
using std::ostream_iterator;
using std::string;

int main()
{
    ofstream even("even.txt");
    ofstream odd("odd.txt");
    ostream_iterator<int> even_iter(even, "\n");
    ostream_iterator<int> odd_iter(odd, " ");
    istream_iterator<int> in_iter(cin), eof;

    while (in_iter != eof)
        if (*in_iter % 2)
            *odd_iter++ = *in_iter++;
        else
            *even_iter++ = *in_iter++;

    return 0;
}
