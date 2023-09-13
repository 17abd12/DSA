//Problem
// 	int list[5]={3,6,9,12,15};
// 	int *pArr= list;	
// 	Your task is to write a piece of code that prints 
// all values stored in the array list using only pointer variable pArr.
//  Do not use the conventional way of printing values by numbering indexes.


#include <iostream>
using namespace std;
int main()
{
    //given 
    int list[5]={3,6,9,12,15};
	int *pArr= list;

    //using a for loop 
    for(int i = 0;i < 5;i++)
    {
        //printing the value of array using pointer notation
        cout << *(pArr + i)<<endl;
    }
    return 0;
}