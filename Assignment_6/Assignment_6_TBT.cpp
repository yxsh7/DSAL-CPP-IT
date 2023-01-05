/*
SI32 Yash Kamthe
GITHUB: https://github.com/yxsh7
Implement In-order Threaded Binary Tree and traverse it in In-order and
Pre-order.
*/
#include<iostream>
using namespace std;
class Ttree
{ public:
  char Data;
  int LFlag,RFlag;
  Ttree *Left,*Right;
  Ttree(char c='\0')
  {  Data=c;
     LFlag=RFlag=1;
     Left=Right=NULL;
  }
};

class Threaded_Tree
{
Ttree *Head;
public:
Threaded_Tree()
{
    Head=new Ttree;
    Head->Right=Head;
}
void Create(char[]);
void PreTrav();
void InTrav();
};

void Threaded_Tree ::Create(char Estr[25])
{
  Ttree *Stk[20], *Temp;
  int Top=-1, I=0;
while(Estr[I]!='\0')
{
 Ttree *Node=new Ttree(Estr[I]);
 Node->Left=Node->Right=Head;
if(isalnum(Estr[I])); //operand
else  //operator
  {
Node->Right=Temp=Stk[Top--];//pop and attach to right
while(Temp->Left!=Head) //till leftmost node
   Temp=Temp->Left;//move 2 left
Temp->Left=Node;// Threaded link
Node->RFlag=0; //Link

Node->Left=Temp=Stk[Top--];//pop and attach to left
while(Temp->Right!=Head)// till rightmost node
   Temp=Temp->Right;//move 2 right
Temp->Right=Node;//Threaded link
Node->LFlag=0;//Link
  }
  Stk[++Top]=Node;//push
  I++;
 }
Head->Left=Stk[Top--]; //pop and attach to left of head
}//end of Create()


void Threaded_Tree::InTrav()
{
Ttree *Temp=Head->Left;
do
 {
 while(Temp->LFlag==0) //follow link to left
    Temp=Temp->Left; //move 2 left
    cout<<Temp->Data; //print it
    Temp=Temp->Right;//follow the thread to right
    cout<<Temp->Data; //print it
    Temp=Temp->Right;//follow link to right
 }
 while(Temp!=Head);
}

void Threaded_Tree::PreTrav()
{
Ttree *Temp=Head->Left;
do
 {
  while(Temp->LFlag==0) //follow link to left
    {
      cout<<Temp->Data;//print it
      Temp=Temp->Left; //move 2 left
    }
   cout<<Temp->Data;//print
   Temp=Temp->Right;//follow the thread 2 right
   Temp=Temp->Right;//follow the link 2 right
 }
 while(Temp!=Head);
}

int main()
{
Threaded_Tree B;
char Estr[25];
cout<<"Enter Postfix Expression: ";
cin>>Estr;

B.Create(Estr);
cout<<" \n----------------------------------\n ";
cout<<" \n Preorder : ";
B.PreTrav();
cout<<" \n----------------------------------\n ";
cout<<" \n Inorder : ";
B.InTrav();
cout<<" \n----------------------------------\n ";

}