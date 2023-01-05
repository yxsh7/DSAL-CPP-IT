/*
SI32 Yash Kamthe
GITHUB: https://github.com/yxsh7
Implement stack as an abstract data type using singly linked list and use
this ADT for conversion of infix expression to postfix, prefix and 
evaluation of prefix and postfix expression.
*/
#include<iostream>
#include<ctype.h>
#include<string.h>
#include<math.h>
using namespace std;
class stack
{
	struct node
	{
	   float   data;
	   node *next;
	};
	node *top;
public:
       stack()
       {
	 top=NULL;
       }
       int empty();
       void push(float);
       float pop();
       int Top();
};

int stack::empty()
{
 if(top==NULL)
	return 1;
else
 return 0;
}

void stack::push(float  x)
{  	node *newnode;
  newnode=new node;
  newnode->data=x;
  newnode->next=top;
  top=newnode;
}

float stack::pop()
{
   node *temp=top;
    float  x;
    top=top->next;
    x=temp->data;
 delete temp;
 return x;
}

int stack::Top()
{	return top->data;	}

int Priority(char Op)
{
if(Op=='(' || Op==')')
	return 0;
if(Op=='+' || Op=='-')
	return 1;
else if(Op=='*' || Op=='/')
	return 2;
else if(Op=='^')
	return 3;
else
	return 4;
}

float Operation(char Op,float A,float B)
{
float P;
if(Op=='*')
	P=A*B;
else if(Op=='/')
	P=A/B;
else if(Op=='+')
	P=A+B;
else if(Op=='-')
	  P=A-B;
else if (Op=='^')
        P=pow(A,B);

return P;
}

void infixtopostfix(char infix[20])
{
  char post[20],x,token;
  int i,j=0;
  stack s;
for(i=0;infix[i]!='\0';i++)
{	token=infix[i];
if(isalnum(token))//alphanumberic
         post[j++]=token;
else
   if(token == '(')
	s.push(token);
   else
	if(token == ')')
     while((x=s.pop())!='(')//pop till )
	       post[j++]=x;
	else
	{
	   while(!s.empty() && Priority(token)<=Priority(s.Top()))
	      {
               post[j++]=s.pop();
              }
	      s.push(token);
	}
}

while(!s.empty())
   post[j++]=s.pop();
  post[j]='\0';
cout<<"\nPostfix Expression=>";
cout<<post;
}

void infixtoprefix(char infix[20])
{
  char prefix[20],x,token;
 int i,j=0;
 stack S;
for(i=strlen(infix)-1;i>=0;i--)
{
  token=infix[i];
if(isalnum(token))
  prefix[j++]=token;
else
  if(token == ')')
  S.push(token);
else
  if(token == '(')
 while((x=S.pop())!=')')
prefix[j++]=x;
else
{
	while(!S.empty() && Priority(token)<Priority(S.Top()))
    {
   prefix[j++]=S.pop();
    }
    S.push(token);
 }
}

while(!S.empty())
   prefix[j++]=S.pop();
prefix[j]='\0';
cout<<"\nPrefix Expression=>";
for(i=strlen(prefix)-1;i>=0;i--)
  cout<<prefix[i];
}

float Postfix_Evaluation(char String[20])
{
    int i;
    char token;
    float op1,op2,Result,val;
    stack  S;
    for(i=0;String[i]!='\0';i++)
  {
    token=String[i];
   if(isalpha(token))
  {
      cout<<"\nEnter the value of "<<token<<"=>";
	 cin>>val;
	 S.push(val);
   }
else if(isdigit(token))
  S.push(token-48);
else
{
 op2=S.pop();
 op1=S.pop();
 Result=Operation(token,op1,op2);
 cout<<"Result: ";
 S.push(Result);
}
}
return S.pop();
}
float Prefix_Evaluation(char Str[20])
{
    int i;
    float Op1,Op2,Result,val;
    stack  S;
    char token;
     for(i=strlen(Str)-1;i>=0;i--)
    {
      token=Str[i];
      if(isalpha(token))// if char
      {	cout<<"\nEnter the value of "<<token<<"=>";
	cin>>val;
	S.push(val);
      }
      else if(isdigit(token))
	   S.push(token-48);
      else
      {
	Op1=S.pop();
	Op2=S.pop();
	Result=Operation(token,Op1,Op2);
	cout<<"Result: ";
	S.push(Result);
      }
}
return S.pop();
}

int main()
{
    int ch;
    char infix[20],post[20],prefix[20];
 do
  {
   cout<<"\n\nSELECT THE CHOICE FROM BELOW\n1:Infix to Postfix\n2:Infix to Prefix\n3:Postfix Evaluation\n4:Prefix Evaluation";
   cout<<"\nEnter your Choice: ";
   cin>>ch;
   switch(ch)
   {
    case 1:
          cout<<"\nEnter infix Expression=>";
          cin>>infix;
	  	  infixtopostfix(infix);
		  break;

    case 2:
          cout<<"\nEnter infix Expression=>";
          cin>>infix;
		  infixtoprefix(infix);
		  break;

   case 3:
          cout<<"\nEnter Postfix Expression=>";
          cin>>post;
	  	  cout<<"\nEvaluated Result=> " <<Postfix_Evaluation(post);
		  break;

    case 4:
          cout<<"\nEnter Prefix Expression=>";
          cin>>prefix;
		  cout<<"\nEvaluated Result=> " <<Prefix_Evaluation(prefix);
		  break;
}
}while(ch!=5);
}



/*output __


SELECT THE CHOICE FROM BELOW
1:Infix to Postfix
2:Infix to Prefix
3:Postfix Evaluation
4:Prefix Evaluation
Enter your Choice: 1

Enter infix Expression=>A+B*C+D

Postfix Expression=>ABC*+D+

SELECT THE CHOICE FROM BELOW
1:Infix to Postfix
2:Infix to Prefix
3:Postfix Evaluation
4:Prefix Evaluation
Enter your Choice: 2

Enter infix Expression=>(A+B)*(C+D)/E

Prefix Expression=>/*+AB+CDE

SELECT THE CHOICE FROM BELOW
1:Infix to Postfix
2:Infix to Prefix
3:Postfix Evaluation
4:Prefix Evaluation
Enter your Choice: 3

Enter Postfix Expression=>ABC*+D+

Evaluated Result=>
Enter the value of A=>2

Enter the value of B=>3

Enter the value of C=>4
Result: Result:
Enter the value of D=>6
Result: 20

SELECT THE CHOICE FROM BELOW
1:Infix to Postfix
2:Infix to Prefix
3:Postfix Evaluation
4:Prefix Evaluation
Enter your Choice: 4

Enter Prefix Expression=>/*+AB+CDE

Evaluated Result=>
Enter the value of E=>3

Enter the value of D=>2

Enter the value of C=>1
Result:
Enter the value of B=>6

Enter the value of A=>5
Result: Result: Result: 11

SELECT THE CHOICE FROM BELOW
1:Infix to Postfix
2:Infix to Prefix
3:Postfix Evaluation
4:Prefix Evaluation
Enter your Choice: 5

Process returned 0 (0x0)   execution time : 128.015 s
Press any key to continue.

*/
