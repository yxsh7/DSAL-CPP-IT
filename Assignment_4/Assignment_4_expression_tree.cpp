/*
SI32 Yash Kamthe
GITHUB: https://github.com/yxsh7
Construct an Expression Tree from postfix and prefix expression. Perform
recursive and nonrecursive In-order, pre-order and post-order traversals.
*/
#include<iostream>
#include<string.h>
using namespace std;

class tree
{
    struct node
    {
        char data;
        node *left,*right;
    };
    node *root;

public:
    tree()
    {
        root=NULL;
    }
// CREATE TREE
void tree_postfix();
void tree_prefix();
// RECURSIVE TRAVERSAL
void recursive_preorder(node *);
void recursive_inorder(node *);
void recursive_postorder(node *);
// NON-RECURSIVE TRAVERSAL
void nonrecursive_preorder();
void nonrecursive_inorder();
void nonrecursive_postorder();

node *return_root()
    {
    return root;
    }
};

//CREATE TREE FROM POSTFIX EXPRESSION
void tree::tree_postfix()
{
    node *s[100];
    int top = -1;
    char postfix_exp[100],token;
    cout<<"\nEnter Postfix Expression: ";
    cin>>postfix_exp;

    for(int i=0; postfix_exp[i]!='\0';i++)
    {
        token = postfix_exp[i];
        node *newnode = new node;
        newnode->data=token;
        newnode->left=newnode->right=NULL;

        if(isalnum(token))
            s[++top]=newnode;
        else
            {
                newnode->right=s[top--];
                newnode->left=s[top--];
                s[++top]=newnode;
            }
        root = s[top];
    }
}

// CREATE TREE FROM PREFIX EXPRESSSION
void tree::tree_prefix()
{
    node *s[100];
    int top = -1;
    char prefix_expression[100], token;
    cout<<"\nEnter Prefix Expression: ";
    cin>>prefix_expression;

    for(int i=strlen(prefix_expression)-1;i>=0; i--)
    {
        token = prefix_expression[i];
        node *newnode = new node;
        newnode->data=token;
        newnode->left=newnode->right=NULL;

        if(isalnum(token))
            s[++top] = newnode;
        else
        {
            newnode->left=s[top--];
            newnode->right=s[top--];
            s[++top] = newnode;
        }
        root = s[top];
    }
}

// RECURSIVE PREORDER TRAVERSAL
void tree::recursive_preorder(node *temp)
{
    if(temp != NULL)
    {
       cout<<"\t"<<temp->data;
       recursive_preorder(temp->left);
       recursive_preorder(temp->right);
    }
}

// RECURSIVE INORDER TRAVERSAL
void tree::recursive_inorder(node *temp)
{
    if(temp != NULL)
    {
        recursive_inorder(temp->left);
        cout<<"\t"<<temp->data;
        recursive_inorder(temp->right);
    }
}

// RECURSIVE POSTORDER TRAVERSAL
void tree::recursive_postorder(node *temp)
{
    if(temp != NULL)
    {
        recursive_postorder(temp->left);
        recursive_postorder(temp->right);
        cout<<"\t"<<temp->data;
    }
}

// NONRECURSIVE PREORDER TRAVERSAL
void tree::nonrecursive_preorder()
{
    node *s[100],*temp=root;
    int top=-1;
	while(temp!=NULL || top>-1)
	{
		while(temp!=NULL)
		    {
			    cout<<"\t"<<temp->data;
			    s[++top]=temp;
			    temp=temp->left;
		    }
		    temp=s[top--];
		    temp=temp->right;
	}
}

// NONRECURSIVE INORDER TRAVERSAL
void tree::nonrecursive_inorder()
{
    node *s[100],*temp=root;
    int top=-1;
	while(temp!=NULL || top>-1)
	{
		while(temp!=NULL)
		    {
			    s[++top]=temp;
			    temp=temp->left;
	    	}
		    temp=s[top--];
	     	cout<<"\t"<<temp->data;
		    temp=temp->right;
	}
}

// NONRECURSIVE POSTORDER TRAVSERSAL
void tree::nonrecursive_postorder()
{
    node *s[100],*temp=root;
    char post[100];
    int i=0,top=-1;
	while(temp!=NULL || top>-1)
	{
		while(temp!=NULL)
		{
			post[i++]=temp->data;
			s[++top]=temp;
			temp=temp->right;
		}
		temp=s[top--];
		temp=temp->left;
	}
    for(i=strlen(post)-1;i>=0;i--)
	  cout<<"\t"<<post[i];
}

int main()
{
    tree ob;
    int ch,choice;

while(true)
{   cout<<"\n1:Create Expression tree using Postfix Expression\n2:Create Expression tree using Prefix Expression\n3:Exit";
    cout<<"\nEnter your choice: ";
    cin>>ch;
    if(ch==1)
        ob.tree_postfix();
    else if(ch==2)
        ob.tree_prefix();
    else
        return 0;
    cout<<"\n1:Use Recursive Traversals \n2:Use Non Recursive Traversals";
    cout<<"\nEnter your choice: ";
    cin>>choice;
switch(choice)
{
  case 1:
	   cout<<"\nRecursive Preorder: ";
	   ob.recursive_preorder(ob.return_root());
	   cout<<"\nRecursive Inorder: ";
	   ob.recursive_inorder(ob.return_root());
           cout<<"\nRecursive Postorder: ";
	   ob.recursive_postorder(ob.return_root());
	   cout<<endl;
	   break;

  case 2:
	   cout<<"\nNonRecursive Preorder: ";
	   ob.nonrecursive_preorder();
	   cout<<"\nNonRecursive Inorder: ";
	   ob.nonrecursive_inorder();
	   cout<<"\nNonRecursive Postorder: ";
	   ob.nonrecursive_postorder();
	   break;
}
}
}
/*
OUTPUT: 
1:Create Expression tree using Postfix Expression
2:Create Expression tree using Prefix Expression
3:Exit
Enter your choice: 1

Enter Postfix Expression: ab*

1:Use Recursive Traversals 
2:Use Non Recursive Traversals
Enter your choice: 2

NonRecursive Preorder:  *       a       b
NonRecursive Inorder:   a       *       b
NonRecursive Postorder: a       b       *
1:Create Expression tree using Postfix Expression
2:Create Expression tree using Prefix Expression
3:Exit
Enter your choice: 2

Enter Prefix Expression: +ab

1:Use Recursive Traversals 
2:Use Non Recursive Traversals
Enter your choice: 1

Recursive Preorder:     +       a       b
Recursive Inorder:      a       +       b
Recursive Postorder:    a       b       +

1:Create Expression tree using Postfix Expression
2:Create Expression tree using Prefix Expression
3:Exit
Enter your choice: 3
*/

