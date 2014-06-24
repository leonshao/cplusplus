#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;

struct Exmpl
{
    Exmpl()
    {
        cout << "Exmpl()" << endl;
    }

    Exmpl(const Exmpl &)
    {
        cout << "Exmpl(const Exmpl &)" << endl;
    }

    ~Exmpl()
    {
        cout << "~Exmpl()" << endl;
    }

    Exmpl & operator=(const Exmpl &)
    {
        cout << "operator=(const Exmpl &)" << endl;
        return *this;
    }
};

void funcA(Exmpl obj)
{
}

void funcB(Exmpl & obj_ref)
{
}

int main()
{
    cout << "dynamic allocation: " << endl;
    Exmpl * ptr = new Exmpl();
    cout << "====" << endl << endl;

    cout << "paramter of funcA(Exmpl obj): " << endl;
    funcA(*ptr);
    cout << "====" << endl << endl;

    cout << "paramter of funcB(Exmpl & obj_ref): " << endl;
    funcB(*ptr);
    cout << "====" << endl << endl;

    /*
    cout << "container push_back: " << endl;
    vector<Exmpl> vec;
    vec.push_back(*ptr);
    cout << "====" << endl << endl;

    cout << "container init: " << endl;
    vector<Exmpl> vec2(5);
    cout << "====" << endl << endl;
    */

    cout << "copy constructor: " << endl;
    Exmpl object = *ptr;
    cout << "====" << endl << endl;

    cout << "assignment: " << endl;
    Exmpl object2;
    object2 = *ptr;
    cout << "====" << endl << endl;

    cout << "delete: " << endl;
    delete ptr;
    cout << "====" << endl << endl;

    return 0;
}
