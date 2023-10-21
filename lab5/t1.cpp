// 1 + 2 * (3 / 4)
// 1 + 2 * [3 * 3 + {4 – 5 (6 (7/8/9) + 10) – 11 + (12*8)] + 14
// 1 + 2 * [3 * 3 + {4 – 5 (6 (7/8/9) + 10)} – 11 + (12*8) / {13 +13}] + 14



#include<string>
#include<iostream>
using namespace std;
// Creating an Array stack
class ArrayStack
{
    private:
        int *Array;// defining int
        int capacity;//defining capcity
        int counter;//defining countef

    public:
        ArrayStack(int x)
        {
            Array = new int[x];
            capacity = x;
            counter = 0;
        }
        //making method push
        void push(int value)
        {
            if(counter == capacity)
            {
                cout << "Stack is full"<<endl;
                return;
            }
            Array[counter] = value;
            counter++;
        }
        //making method pop
        int pop()
        {
            if(counter == 0)
            {
                cout << "Stack is empty"<<endl;
                return 0;
            }
            int value = Array[counter - 1];
            counter--;
            return value;
        }
        // returning the topmost number
        int peak()
        {
            if(counter == 0)
            {
                cout << "Stack is empty"<<endl;
                return 0;
            }
            int value = Array[counter - 1];
            return value;
        }
        // checking if full or not
        bool isFull()
        {
            return capacity == counter;
        }
        // checking if empty or not
        bool isEmpty()
        {
            return counter == 0;
        }
        //dleeting Array
        void Clear()
        {
            delete[] Array;
        }


};
int main()
{
    // creating an array of braces
    char Braces[6] = {'(','[','{',')',']','}'};
    // taking string as an inputy
    string String_name;
    cout << "Enter the expression: ";
    getline(cin,String_name);
    // creating a stack
    ArrayStack *Stack_name = new ArrayStack(12);

    //looping till lenght of string
    ArrayStack *Error = new ArrayStack(12);
    for(int x = 0;x <  String_name.length();x++)
    {
        //checking for first three items of braces

        for(int i = 0;i < 3;i++)
        {
            
            if(String_name[x] == Braces[i])
            {
                //if char is opening braces than pushing it counter part
                Stack_name->push(Braces[i+3]);
                Error->push(x);
            }
        }

        if(String_name[x] == ')'|| String_name[x] == '}' || String_name[x] == ']')
        {
            char z = Stack_name->pop();


            // if opening and closing part doesnt match than displaying an error
            if(z != String_name[x])
            {
                Stack_name->push('(');
                Error->push(x);
                break;
            }
            Error->pop();
        }
    }

    //checking if stack is empty or not
    if(Stack_name->isEmpty())
        cout << endl << "Yes the braces are correct"<<endl;
    else
        cout << endl << "No This is not correct error at "<<Error->pop()<<endl;

    //releasing the memory
    Stack_name->Clear();
    return 0;
}