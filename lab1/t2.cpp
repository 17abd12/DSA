// PROVIDED CODE IN TASK 2 
//Consider the following program and answer the questions.
//Answers in t2.txt
//Code of Question 3
#include <iostream>
using namespace std;
int main()
{
int a, *pa;      // Statement 1
pa = &a;           // Statement 2
cout<<"pa = &a --> pa = "<<pa<<endl<<endl;
pa = pa * 1;      // Statement 3
cout<<"pa = pa * 1 --> pa = "<<pa<<endl<<endl; 
pa = pa * 3;      // Statement 4
cout<<"pa = pa * 3 --> pa = "<<pa<<endl<<endl; 
pa = pa * 2;      // Statement 5
cout<<"pa = pa * 2 --> pa = "<<pa<<endl<<endl;	
return 0;	
}
