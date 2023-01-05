/*
SI32 Yash Kamthe
GITHUB: https://github.com/yxsh7
Represent a graph of your college campus using adjacency list
/adjacency matrix. Nodes should represent the various
departments/institutes and links should represent the distance between
them. Find minimum spanning tree
a) Using Kruskal's Algorithm b) Using Primims Algorithm
*/
#include<iostream>
#include<string.h>
using namespace std;
class Graph
{
char Vnames[10][10];
int cost[10][10],n;
public:
Graph();
void creat_graph();
void display();
int Position(char[]);
void kru();
};
Graph::Graph()
{
n=0;
for(int i=0;i<10;i++)
for(int j=0;j<10;j++)
 {
   cost[i][j]=999;
 }
}
void Graph::creat_graph()
{
char ans,Start[10],End[10];
int wt,i,j;
cout<<"Enter number of nodes";
cin>>n;
cout<<"\n Enter vertex name:";
for(i=0;i<n;i++)
          cin>>Vnames[i];
do
{
cout<<"\nEnter Start and end point of edge";
cin>>Start>>End;
cout<<"Enter weight";
cin>>wt;
i=Position(Start);
j=Position(End);
cost[i][j]=cost[j][i]=wt;
cout<<"\nMore Edges ";
cin>>ans;
}while(ans=='y' || ans=='Y');
}


void Graph::display()
{
int i,j;
for(i=0;i<n;i++)
{
 cout<<"\n";
 for(j=0;j<n;j++)
		 cout<<"\t"<<cost[i][j];
}
}
int Graph::Position(char key[10])
{
for(int i=0;i<n;i++)
if(strcmp(Vnames[i],key)==0)
		return i;
return -1;
}







void Graph::kru()
{		 int i,j,x,y,Total_cost=0,min,gr=1,flag=0,temp, v[10]={0};
while(flag==0)
 {	 min=999;
 for(i=0;i<n;i++)  //find the minimum edge 
{	 for(j=0;j<n;j++)
		  {   	 if(cost[i][j]<min)
			{	min=cost[i][j];
				x=i;
				y=j;
		       }//end of if 
}//end inner for 
}//end of outer for 

if(v[x]==0 && v[y]==0) //both are not visited   
{	v[x]=v[y]=gr;
gr++;
}
else if(v[x]!=0 && v[y]==0)// x visited , y not visited
	v[y]=v[x];  //assign group of x to y 
else if(v[x]==0 && v[y]!=0)// x not  visited,y visited
	v[x]=v[y];//assign group of y to x 
else
{	if(v[x]!=v[y]) // both belong to diffrent group 
	{	temp=v[x];
		for(i=0;i<n;i++)
		{	if(v[i]==temp)
				v[i]=v[y];
		}//end of for 
	}//end of if 
}//end of else 
cost[x][y]=cost[y][x]=999;
Total_cost = Total_cost + min;
cout<<"\n"<<Vnames[x]<<"\t"<<Vnames[y]<<"\t"<<min;
//print visit array after every step
  temp=v[0]; flag=1;
   for(i=0;i<n;i++)
   {	   if(temp!=v[i])
	   {	 flag=0;
		 break;
	   }
   }//end of inner for 
}//end of while 
cout<<"\nTotal cost of tree="<<Total_cost;
}

int main()
{
Graph ob;
ob.creat_graph();
ob.display();
ob.kru();
}






/******************************OUTPUT:**********************************


Enter number of nodes9

 Enter vertex name:IT
ENTC
CIVIL
MECH
ELEC
CS
SW
PD
RO

Enter Start and end point of edgeIT
ENTC
Enter weight65

More Edges Y

Enter Start and end point of edgeENTC
CIVIL
Enter weight42

More Edges Y

Enter Start and end point of edgeMECH
ELEC
Enter weight2

More Edges Y

Enter Start and end point of edgeCIVIL
MECH
Enter weight38

More Edges Y

Enter Start and end point of edgeELEC
CS
Enter weight75

More Edges Y

Enter Start and end point of edgeCS
SW
Enter weight56

More Edges Y

Enter Start and end point of edgeSW
PD
Enter weight98

More Edges Y

Enter Start and end point of edgePD
RO
Enter weight88

More Edges Y

Enter Start and end point of edgeRO
IT
Enter weight77

More Edges Y

Enter Start and end point of edgeIT
CS
Enter weight4

More Edges N

        999     65      999     999     999     4       999     999     77
        65      999     42      999     999     999     999     999     999
        999     42      999     38      999     999     999     999     999
        999     999     38      999     2       999     999     999     999
        999     999     999     2       999     75      999     999     999
        4       999     999     999     75      999     56      999     999
        999     999     999     999     999     56      999     98      999
        999     999     999     999     999     999     98      999     88
        77      999     999     999     999     999     999     88      999
MECH    ELEC    2
IT      CS      4
CIVIL   MECH    38
ENTC    CIVIL   42
CS      SW      56
IT      ENTC    65
ELEC    CS      75
IT      RO      77
PD      RO      88
Total cost of tree=447
*******************************************************/