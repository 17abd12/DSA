/*Task 1
Rewrite this program using pointers in place of arrays
(use dynamic memory allocation operators new and delete). 
The syntax is int *salArray= new int[size]; and for deletion delete [] salArray.*/


#include<iostream>
using namespace std;
int main(void)
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    
    int *salary = new int[size]; //allocating memory dynamically
    //----Code provided by instructor------//
    int i;
    for (i=0;i<size;++i)
      {
        cout<<"Enter Salary: ";
        cin>>*(salary + i);
     }
    for (i=0;i<size;++i)
        *(salary + i)=*(salary + i)+*(salary + i)/(i+1);//conerting into pointer notation form
    delete[] salary;        //freeing the allocated memory
    return 0;

}
