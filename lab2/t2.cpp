# include <iostream>
using namespace std;
void analyze_pointer(int *ptr);
int main()
{
    int stack_i = 8; //declaring a stack
    cout << "printing value and address of variable allocated on stack" << endl;
    analyze_pointer(&stack_i);//analyzing

    int *heap_i = new int(8);//declaring a heap variable
    cout << "printing value and address of variable allocated on head" << endl;
    analyze_pointer(heap_i);
    delete heap_i;//freeing the allocated memory
}
void analyze_pointer(int *ptr)
{
    cout << "The addresss of the pointer is " << ptr << endl;
    cout << "The value inside the pointer is "<< *ptr << endl;
}