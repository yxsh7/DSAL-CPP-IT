/* 
SI32 Yash Kamthe
Implement Circular Queue using Array. Perform following operations on
it.
a) Insertion (Enqueue) b) Deletion (Dequeue) c) Display
(Note: Handle queue full condition by considering a fixed size of a
queue.)
*/
#include<iostream>
#define max 6
using namespace std;
#include <stdlib.h>

class Queue
{
    int q[max],front,rear;

    public: 
    Queue()
    {
        front = 0;
        rear = -1;

        for(int i=0;i<max;i++)
            q[i] = -1;
    }

    int is_Queue_Full();
    int is_Queue_Empty();
    int En_Queue(int);
    int D_Queue(int&);
    void Display();
};
    int Queue::is_Queue_Full()
    {
     if(rear!=-1 && front==(rear+1)%max)
	      return 1;
	 else
          return 0;
   }

   int Queue::is_Queue_Empty()
   {
     if(rear==-1)
	    return 1;
     else
        return 0;
   }

   int Queue::En_Queue(int Data)
   {
    if(is_Queue_Full())
        return false;
    else
        rear=(rear+1)%max;
        q[rear]=Data;
        return true;
    }

    int Queue::D_Queue(int& Data)
    {
        if(!is_Queue_Empty())
        {
            Data=q[front];
            q[front]=-1;
            front=(front+1)%max;

            if(front==(rear+1)%max)
            {
                front=0;
                rear=-1;
            }          
            return true;
        }
        return false;
    } 

void Queue::Display()
   {
        for(int i=0; i<max;i++)
        cout<<" "<<q[i];
    }

int main()
{
    Queue CQ;
    int element, choose;
    char input;

    do 
        {
            cout<<"\n MENU \n 1.INSERT ELEMENT\n 2.DELETE ELEMENT\n 3.EXIT\n ";
            cout<<"Enter your choice: ";
            cin>>choose;
            switch (choose)
            {
            case 1:
                for(int x=0; x<max; x++)
                {
                cout<<"Enter Element: ";
                cin>>element;
                
                

                if(CQ.En_Queue(element))
                    cout<<"Success \n";
                
                else
                    cout<<"\nQueue Full, cannot insert an element";
                }
                break;
                

            case 2:
                if(CQ.D_Queue(element))
                    cout<<"\n Element Deleted: "<<element<<"\n";
                else
                    cout<<"Queue Empty cannot remove element";
                break;
            
            case 3:
            exit(0);
            }
            CQ.Display();
            cout<<"\n Do you want to continue(y/n): ";
            cin>>input;

        }while(input=='y');
            cout<<"Queue:";
            CQ.Display();
        return 1;
}

/*  
OUTPUT:



 MENU 
 1.INSERT ELEMENT
 2.DELETE ELEMENT
 3.EXIT
 Enter your choice: 1
Enter Element: 5
Success 
Enter Element: 9
Success 
Enter Element: 1
Success 
Enter Element: 3
Success 
Enter Element: 4
Success 
Enter Element: 6
Success 
 5 9 1 3 4 6
 Do you want to continue(y/n): y

 MENU 
 1.INSERT ELEMENT
 2.DELETE ELEMENT
 3.EXIT
 Enter your choice: 2

 Element Deleted: 5
 -1 9 1 3 4 6
 Do you want to continue(y/n): y

 MENU 
 1.INSERT ELEMENT
 2.DELETE ELEMENT
 3.EXIT
 Enter your choice: 2

 Element Deleted: 9
 -1 -1 1 3 4 6
 Do you want to continue(y/n): y

 MENU 
 1.INSERT ELEMENT
 2.DELETE ELEMENT
 3.EXIT
 Enter your choice: 3

*/
    
