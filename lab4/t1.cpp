/* C++ Program to Implement Circular Doubly Linked List
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

//Creating a global node using struct
struct node
{
		int info;
		struct node *next;
		struct node *prev;
};


//Making a doubly linked class
class DoubleCircularList
{
    public:
	int counter = 0;
    node *start;
    node *last;

        DoubleCircularList(){
            start = NULL;
            last = NULL;
        }

		/*
		 *INSERTS ELEMENT AT BEGINNING
		 */
		void insertAtStart(){
			int value;
			cout<<endl<<"Enter the element to be inserted: ";
			cin>>value;

            node *new_node = new node;
            new_node->info = value;
            if(start == nullptr)
            {
                start=new_node;
                last=new_node;
                start->next = last;
                start->prev = last;
                last->next = start;
                last->prev = start;
                counter++;
            }
            else
            {
                new_node->next = start;
                new_node->prev = last;
                start = new_node;
                counter++;
              
            }

		}

		/*
		 *INSERTS ELEMNET AT LAST
		 */
		void insertLast(){
			int value;
			cout<<endl<<"Enter the element to be inserted: ";
			cin>>value;
            node *new_node = new node;
            new_node->info = value;
            if(start == nullptr)
            {
                start=new_node;
                last=new_node;
                start->next = last;
                last->next = start;
                counter++;
            }
            else
            {
                new_node->next = start;
                new_node->prev = last;
                last->next = new_node;
                last = last->next;
                counter++;
              
            }
		}
		/*
		 *INSERTS ELEMENT AT POSITION
		 */
		void insertAtPos(){
			int value, pos, i;
			cout<<endl<<"Enter the element to be inserted: ";
			cin>>value;
			cout<<endl<<"Enter the postion of element inserted: ";
			cin>>pos;

            node *temp = new node;
            temp->info = value;
            node *temp2 = start;
			for(int y = 0;y < pos - 1;y++)
            {
                temp2 = temp2->next;
            }

            temp->next = temp2->next;
            temp->prev = temp2;
            temp2->next = temp; 
            counter++;
			
		}
		/*
		 * Delete Node at Particular Position
		 */
		void deleteAtPos()
		{
			int pos, i;
			node *ptr, *s;
			if (start == last && start == NULL)
			{
				cout<<"List is empty, nothing to delete"<<endl;
				return;
			}
			cout<<endl<<"Enter the postion of element to be deleted: ";
			cin>>pos;

			//your code here
            node *temp2 = start;
			for(int y = 0;y < pos - 1;y++)
            {
                temp2 = temp2->next;
            }

            temp2->next = temp2->next->next;
            temp2->next->prev = temp2->next->prev->prev;
            counter--;



		}
		/*
		 * Display Elements of the List
		 */
		void display(){
			//your code here
            node *temp = start;
			for(int i = 0;i < counter - 1;i++)
            //while(temp != nullptr)
            {
                cout << temp->info<<",";
                temp= temp->next;
            }
            cout << temp->info<<endl;
            // cout <<temp->next->info<< endl;

		}

};

/*
 * Main: Contains Menu
 */
int main(){
    int userChoice;
    DoubleCircularList cdl;
    while (1){
        cout<<"\n-------------------------------"<<endl;
        cout<<"Operations on Doubly Circular linked list"<<endl;
        cout<<"\n-------------------------------"<<endl;
        cout<<"1.Insert at Beginning"<<endl;
        cout<<"2.Insert at Last"<<endl;
        cout<<"3.Insert at Specific Position"<<endl;
        cout<<"4.Delete at Specific Position"<<endl;
        cout<<"5.Display List"<<endl;
        cout<<"6.Exit"<<endl;
        cout<<"Enter your choice : ";
        cin>>userChoice;
        switch(userChoice){
        case 1:
            cdl.insertAtStart();
            break;
        case 2:
            cdl.insertLast();
            break;
        case 3:
            cdl.insertAtPos();
            break;
        case 4:
            cdl.deleteAtPos();
            break;
        case 5:
            cdl.display();
            break;
        case 6:
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
    return 0;
}
