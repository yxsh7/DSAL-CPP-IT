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
void prims();
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

void Graph::prims()
{	 int cnt=1,b,i,j,x,y,Total_cost=0,min,visit[10]={0};
 char start[10];
cout<<"\n Starting node=";		 
cin>>start;
 x=Position(start);
 visit[x]=1;
while(cnt<n)
 {	 
min=999;
 for(i=0;i<n;i++)
 {
 	if(visit[i]==1)
 	{
        for(j=0;j<n;j++) // find minimum from adjacent 
         {   if(cost[i][j]<min && visit[j]==0) //not visited 
            {	 min=cost[i][j];
				 x=i;
				 y=j;
            }//end of if 
        }//end of inner for 
     }//end of if 
  }//end of outer for 
//outer for find minmum from all adjacent that are visited 

   cout<<"\n"<<Vnames[x]<<"\t"<<Vnames[y]<<"\t"<<min;
   Total_cost=Total_cost+min;
   cost[x][y]=cost[y][x]=999;
  visit[y]=1;
  cnt++;
}//end of while 
cout<<"\nTotal cost of tree=>"<<Total_cost;
}//end of prims()

int main()
{
Graph G1;
G1.creat_graph();
G1.display();
G1. prims();
}







//OUTPUT:-

/*
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
Enter weight45

More Edges Y

Enter Start and end point of edgeENTC
CIVIL
Enter weight65

More Edges Y

Enter Start and end point of edgeCIVIL
MECH
Enter weight96

More Edges Y

Enter Start and end point of edgeMECH
ELEC
Enter weight35

More Edges Y

Enter Start and end point of edgeELEC
CS
Enter weight59

More Edges Y

Enter Start and end point of edgeCS
SW
Enter weight77

More Edges Y

Enter Start and end point of edgeSW
PD
Enter weight36

More Edges Y

Enter Start and end point of edgePD
RO
Enter weight88

More Edges Y

Enter Start and end point of edgeIT
CS
Enter weight58

More Edges Y

Enter Start and end point of edgeIT
PD
Enter weight66

More Edges N

        999     45      999     999     999     58      999     66      999
        45      999     65      999     999     999     999     999     999
        999     65      999     96      999     999     999     999     999
        999     999     96      999     35      999     999     999     999
        999     999     999     35      999     59      999     999     999
        58      999     999     999     59      999     77      999     999
        999     999     999     999     999     77      999     36      999
        66      999     999     999     999     999     36      999     88
        999     999     999     999     999     999     999     88      999
 Starting node=CIVIL

CIVIL   ENTC    65
ENTC    IT      45
IT      CS      58
CS      ELEC    59
ELEC    MECH    35
IT      PD      66
PD      SW      36
PD      RO      88
Total cost of tree=>452
Process returned 0 (0x0)   execution time : 162.903 s
Press any key to continue.
*/