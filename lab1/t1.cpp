// Problem Statement
// Write code to find the memory in bytes occupied by int, long, double, float and char.

#include <iostream>
using namespace std;
int main()
{
    // for size of int
    cout << "The size of int is "<< sizeof(int)<< " Bytes" <<endl;
    // for size of char
    cout << "The size of char is "<< sizeof(char) << " Bytes" << endl;
    // for size of float
    cout << "The size of float is "<< sizeof(float) <<  " Bytes" <<endl;
    // for size of double
    cout << "The size of double is "<< sizeof(double) << " Bytes" << endl;
    // for size of long
    cout << "The size of long is "<<sizeof(long) << " Bytes" << endl;
    return 0;
}