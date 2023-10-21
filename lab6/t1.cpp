#include<iostream>
using namespace std;

// Creating a class Circluar Queue 
class queue
{
    private:
        int *Array;
        int capacity;
        int pointer;
        int ptr2;
    public:

    // creating a constructor
    queue(int value)
    {
        capacity = value;
        pointer =   0;
        Array = new int(value);
        ptr2 = 0;
    }
    //adding new elemet in a circulas
    bool Enqueue(int value)
    {

        if(pointer - ptr2 >= capacity && pointer >= capacity)
        {
            cout << "Queue Already full"<<endl;
            return false;
        } 
        Array[pointer % capacity] = value;
        pointer++;
        return true;
    }
    // remeving first element from a circular4 queue
    int Dequeue()
    {

        if(ptr2 >= pointer)
        {
            cout << "No value to return"<<endl;
            return -1;
        }
        else
        {
            int value =  Array[ptr2%capacity];
            ptr2++;
            return value;
        }
    }
    //checking if queue is empty or not
        bool isEmpty() 
        {
            return ptr2 >= pointer;


        }
    // checking if Queue is full or not
        bool isFull()
        {
            return pointer - ptr2 == capacity;
        }
    // deleting all element from an array
    void Clear()
    {
        delete[] Array;
    }
    // printing all element in an array
    void print()
    {
        for(int i = ptr2;i < pointer;i++)
        {
            cout <<Array[i%capacity]<<"  ,   ";
        }
        cout << endl;
    }

};

// creating a main class
int main()
{
    //creating a flag
    int x = 1;
    //creating a pointer of a queue
    queue *Q = new queue(6);
    // creating patient id
    int patient = 0;
    while(x)
    {
        // Creating a menu of Management system
        cout << "0-Exit"<<endl;
        cout<<"1-Register patient"<<endl;
        cout << "2-Serve patient"<<endl;
        cout <<"3-Cancel All Appointments "<< endl;
        cout<< "4-Can Doctor Go Home? "<<endl;
        cout << "5-Show all patients"<<endl;
        cout << "Choose an option:  ";
        cin >> x;
        cout <<endl<<endl<<endl;
        // if insertion insert
        if(x == 1)
        {
            bool result = Q->Enqueue(patient);
            if(result)
            {
                cout << "patient "<<patient<<" is added to queue"<<endl;
                patient++;
            }
            else
                cout << "No more space left"<< endl;
        }
        else if (x==2)
        {
            int x = Q->Dequeue();
            cout <<"patient "<<x << " is served"<<endl;
        }
        else if(x == 3)
        {
            Q->Clear();
            cout <<"All appointments Are cancelled"<< endl;
            break;
        }
        else if(x == 4)
        {
            if(Q->isEmpty())
            {
                cout << "Doctor can go Home"<<endl<<endl;
            }
            else{
                cout << "Doctor can Not go Home"<<endl<<endl;
            }
        }
        else if(x==5)
        {
            Q->print();
        }
    }
    // Deleting memory allocated by heap
    delete Q;
    return 0;
}