#include <iostream>

using namespace std;
// using Node defined in help file of lab
class Node //classifying node of linked list
{
public:
    int value;
    Node *next;
};
Node* head = NULL; 
//initialising head of linked list
void insertAtHead(int new_value)
{

    Node *temp = head;//creating a pointee which point to head
    Node *new_node=new Node();//creating new node 
    new_node->value = new_value;
    new_node->next = temp;//inserting value and next in new node
    head = new_node;//making new head

 
}

void insertAtLocation(int location, int new_value)
{
    //starting index is 1 
    int i = 1;
    Node *temp = head; 
    //if location equal to 1 than head will be updated
    if (location == 1)
    {
        Node *new_node = new Node();
        new_node->value = new_value;
        new_node->next = head; 
        head = new_node;
        return;
    }
    //moving to a spcific position beforwe inserting a new node
    while (i + 1 < location)
    {
        if (temp == nullptr)
        {
            cout << "Not enough length" << endl;
            return;
        }
        temp = temp->next;
        i++;
    }
    //inserting new node in Code
    Node *new_node = new Node();
    new_node->value = new_value;
    new_node->next = temp->next;
    temp->next = new_node;
}

    


void del(int del_value)
{
    Node *temp = head;
    //first node is indexed 1 instead of 1
    int i = 1;
    if(!del_value)
    {
        head = head->next;
        return;
    }
    // moving to a specific positon before deleting Node

    while(del_value > i + 1)
    {
        if(temp->next == nullptr)
        {
            cout<<"Not enough space"<<endl;
        }
        cout<<i<<endl;
        temp = temp->next;
        i++;
    }
    //Conde for deleting Node
    temp->next = temp->next->next;

   
}

void displayList()
{

    Node *temp = head;
    //While temp is not equal to null printing the value of node
    while(temp->next != nullptr)
    {
        cout << temp->value<<"->";
        //and moving to next Node
        temp = temp->next;
            }
        cout << temp->value<<endl;
   

}
void countList()
{
     Node *temp = head;
     //initialing count = 0
     int count =0;
    while(temp != nullptr)
    {
        //adding 1 element to count
        count++;
        //moving to next element in list

        temp = temp->next;
            }
        cout <<"\nThe number Nodes are: "<< count<<endl<<endl;   
    
        
}

int main()
{

    //Code was wrtien By MA,AM
    while (1)
    {
        char a; //drawing menu
        cout << " Select from one of the following\n A.Create a node or Insert at HEAD \n B.Display Linked list entries \n C.Insert at location \n D.Delete from location\n E.Count from elements\n" << endl;
        cin >> a;
        switch (a) {
            case 'A':
                cout << "\nInsert any value to Create a node\n" << endl;
                int a1;
                cin >> a1;
                insertAtHead(a1);
                break;
            case 'B':
                cout << "\nDisplay Linked list entries\n" << endl;
                displayList();
                break;
            case 'C':

                cout << "\nChoose which location to enter the value\n" << endl;
                cout << "\n" << endl;
                int b1, b2;
                cin >> b1;
                cout << "\nChoose the value to be entered\n" << endl;
                cin >> b2;
                cout << "\n\n" << endl;
                insertAtLocation(b1, b2);

                break;
            case 'D':
                cout << "Delete from entry location" << endl;
                int d1;
                cin >> d1;
                del(d1);
                break;
            case 'E':
                countList();
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}
