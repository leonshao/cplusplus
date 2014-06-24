#include <iostream>
#include <fstream>  // ifstream, ofstream, fstream
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;
using std::ofstream;

ofstream& open_file_out(ofstream& out, string file)
{
    // first close/clear
    out.close();
    out.clear();

    out.open(file.c_str());
    return out;
}

ifstream& open_file_in(ifstream& in, string file)
{
    in.close();
    in.clear();

    in.open(file.c_str(), ifstream::binary);
    return in;
}

ifstream& print_stream(ifstream& in)
{
    char val;
    // default is to skip \n, need to unset the skip before in >> val
    in.unsetf(ifstream::skipws);

    while(in >> val, !in.eof())
    {
        cout << val;
    }
    in.clear();
    return in;
}

int main()
{
    string file="file.txt";
    ofstream out;
    open_file_out(out, file);
    out << "hello" << endl;
    out << "world" << endl;
    out.close();

    ifstream in;
    open_file_in(in, file);
    print_stream(in);
    return 0;
}
