#include <iostream>
#include <string>
#include <sys/time.h>
#include <stdio.h>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    struct timeval tvTime;
    gettimeofday(&tvTime, NULL);
    cout << "tv_sec size: " << sizeof(tvTime.tv_sec) << ", value: " << tvTime.tv_sec << endl;
    cout << "tv_usec size: " << sizeof(tvTime.tv_usec) << ", value: " << tvTime.tv_usec << endl;
    cout << "current usec: " << (tvTime.tv_sec * 1000) + (tvTime.tv_usec / 1000) << endl;
    cout << "current usec in hex: 0x" << std::hex << (tvTime.tv_sec * 1000) + (tvTime.tv_usec / 1000) << endl;
    cout << "size: " << sizeof((tvTime.tv_sec * 1000) + (tvTime.tv_usec / 1000)) << endl;
    printf("%016lx\n", ((uint64_t)tvTime.tv_sec * 1000) + ((uint64_t)tvTime.tv_usec / 1000));
    cout << tvTime.tv_sec << endl;
    cout << tvTime.tv_sec - 1160370232 << endl;
    return 0;
}
