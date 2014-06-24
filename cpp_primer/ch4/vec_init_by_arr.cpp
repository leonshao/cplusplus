#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
    int arr[] = {0, 1, 2, 3, 4};
    vector<int> ivec(arr, arr + 5);

    for (vector<int>::iterator itr = ivec.begin(); itr != ivec.end(); itr++)
        cout << *itr << " ";

    cout << endl;

    int *p = new int[ivec.size()];
    for (vector<int>::size_type i = 0; i < ivec.size(); i++)
        *(p + i) = ivec[i];

    for (int *q = p; q != p + ivec.size(); q++)
        cout << *q << " ";

    cout << endl;

    delete [] p;

    return 0;
}
