/*
SI32 Yash Kamthe
Consider a student database of SEIT class (at least 15 records). Database
contains different fields of every student like Roll No, Name and
SGPA.(array of structure)
a) Design a roll call list, arrange list of students according to roll numbers
in ascending order (Use Bubble Sort)
b) Arrange list of students alphabetically. (Use Insertion sort)
c) Arrange list of students to find out first ten toppers from a class. (Use
Quick sort)
d) Search students according to SGPA. If more than one student having
same SGPA, then print list of all students having same SGPA. e) Search a particular student according to name using binary search
without recursion. (all the student records having the presence of search
key should be displayed)
(Note: Implement either Bubble sort or Insertion Sort.)
GITHUB: https://github.com/yxsh7
*/
using namespace std;
#include <iostream>
#include <string.h>
int const size=3;

struct student 
{
	int rno;
	char name[20];
	float SGPA;

};

void accept(struct student list[size]);
void display(struct student list[80]);
void bubbleSort(struct student list[size]);
void insertSort (struct student list [size]);
void linearsearch (struct student list [size]);
void binarysearch (struct student list [size]);
void putdata(struct student list [size],int n);
void quicksort(struct student list[size], int left, int right);

main()
{

	int ch,i;
	struct student data[20];
	accept(data);
	while(true)
	{
	cout <<"\n 1: Bubble Sort";
	cout <<"\n 2. Insert Sort";
	cout <<"\n 3. Quick Sort";
	cout <<"\n 4. Linear Search";
	cout <<"\n 5. Binary Search";
	cout <<"\n 6: Exit";
	cout <<"\n Select Your Choice ";
	cin>>ch;
	
	switch(ch)
	{
	case 1:
    cout<<"\nRoll numbers in ascending order ";
	bubbleSort(data);
	display(data);
	break;
	
	case 2:
    cout<<"\n\nList of records alphabetically";
	insertSort(data);
	display(data);
	break;

	case 3:
	cout<<"\nList of students according to first ten toppers from a class";
    quicksort(data,0,size-1);
    putdata(data,size);
    cout<<"\n\n";
    break;

	case 4:
	linearsearch(data);
	break;
	
	case 5:
	binarysearch(data);
	break;

	case 6:
	return 1;
	
	}
	}
}
		

void accept(struct student list[size])
{
	int i;
	for (i=0; i < size; i++)
	{
		cout <<"enter rno,name,SGPA \n";
		cin >> list[i].rno >> list[i].name >> list[i].SGPA;
		
	}
}

void putdata(struct student S[10],int n)
{
      cout<<"\n Rollno\tName\tSGPA";
      for(int i=0;i<n;i++)
      cout<<"\n"<<S[i].rno<<"\t"<<S[i].name<<"\t"<<S[i].SGPA;
}

void display (struct student list[80])
{
	int i;
	cout <<"\n rno \t Name \t SGPA \n";
	for (i=0; i < size; i++)
{
	cout <<"\n"<< list[i].rno <<"\t" <<list[i].name << "\t" <<list[i].SGPA;
}
}

void bubbleSort (struct student list[size])
{
	int i,j;
	struct student temp;
	for (i=0; i<size-1;i++)
	{
		for (j=0; j<(size-1-i); j++)
		{
			if(list[j].rno > list[j+1].rno)
			{
				temp = list[j];
				list[j]= list[j+1];
				list[j+1]=temp;
			}
		}
	}
}
void insertSort(struct student list[size])
{
	int k,j;
	struct student temp;
	
	for (k=1;k<size;k++)
	{
		temp=list[k];
		j=k-1;
		
		while (strcmp(list[j].name,temp.name)>0 && j>=0)
		{
		
		list[j+1]=list[j];
		--j;
	    }
	list[j+1]=temp;
	
	
	}
}

void linearsearch(struct student list[size])
{
	float SGPA;
	int i;
	cout <<"\n enter SGPA";
	cin>>SGPA;
	cout <<"\n rno \t Name \t SGPA \n";
	for (i=0;i<size;i++)
	{
		if (SGPA==list[i].SGPA)
		cout <<"\n"<<list[i].rno<<"\t"<<list[i].name<<"\t"<<list[i].SGPA;
	}
}

void binarysearch(struct student list [size])
{
	int k,lower,upper,mid;
	char search[80];
	cout<<"enter name of student you want to search ";
	cin>>search;
	lower=0;
	upper= size -1;
	mid=(lower+upper)/2;
	while (lower<=upper)
	{
		if(strcmp(list[mid].name,search)<0)
		{
		lower=mid+1;
		}
		
		else if (strcmp(list[mid].name,search)==0)
		{
			cout<<"\n"<<list[mid].rno<<"\t"<<list[mid].name<<"\t"<<list[mid].SGPA;
			break;
		}
		else
		{
		upper = mid-1;
		mid = (upper+lower)/2;
		}

	}
	if(lower > upper)
	{
	cout << search<<"not found in the list";
	}
}

int partition(struct student list[size],int left,int right)
{
     struct student pivot,temp;
     pivot = list[left];
     int Pos_pivot=left;
     while (left < right)
        {
                while ((list[right].SGPA < pivot.SGPA) && (left <= right))
	      right--;
                while ((list[left].SGPA >= pivot.SGPA) && (left <= right))
	      left++;
                if(left<right)
                     {   temp=list[right];
                         list[right] = list[left];
                         list[left] =temp;      }
        }
      if(Pos_pivot!=right)

        { list[Pos_pivot]=list[right];  list[right]=pivot;  }

       return right;


}
void quicksort(struct student list[size], int left, int right)
{
     int pivot=partition(list,left,right);

     if (left < pivot)
      {
          quicksort(list, left, pivot-1);
      }
      if (right > pivot)
      {
          quicksort(list, pivot+1, right);
      }
}


