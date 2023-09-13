// a)	Write code of a function that swaps values of variables a and b. Input to the function should be the address of both the variables.
// b)	Write code of a function that swaps values of the variables a and b using pointer-to-pointer variables ppa and ppb.
// Problem

#include <iostream>
using namespace std;
void swap(int*,int*); // defining the prototype of function
int main()
{
    int a=5, b=10; 
	int *pa=&a; //pa and pb are pointer variables of type int. 
	int *pb=&b;
    int **ppa = &pa;
    int **ppb = &pb;

    //priting value before swapping
    cout <<"Value of a before swapping is "<<**ppa<<" And value of b before swaping is " <<**ppb << endl;
    swap(ppa,ppb);
    //printing value after swapping
    cout <<"Value of a after swapping is "<<**ppa<<" And value of b after swaping is " << **ppb;

}

// writing a function to take input as addresses and swap variables
void swap(int** a,int** b)
{
    int *temp = *a;
    *a = *b;
    *b = temp;
}