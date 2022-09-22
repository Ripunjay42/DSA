/*2. Write a program using templates to sort a list of elements.Give user the option to perform
sorting using Insertion sort, Bubble sort or Selection sort.*/
#include<iostream>
using namespace std;
template <class T>
void bubble_sort(T *a,int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		if(a[i]>a[j+1])
		{
			a[j]=a[j]^a[j+1];
			a[j+1]=a[j]^a[j+1];
			a[j]=a[j]^a[j+1];
		}
	}
}
template <class T>
void selection_sort(T *a,int n)
{
	int i,j,t,loc;
	for(i=0;i<n;i++)
	{	
		loc=i;
		for(j=i+1;j<n;j++)
		{if(a[loc]>a[j])
			{
				loc=j;
			}
		}
		t=a[loc];
		a[loc]=a[i];
		a[i]=t;
	}
}
template <class T>
void InsertionSort(T *a, int n)
{
	int i, j;
	T temp;
    for (int i = 1; i < n; ++i)
	{
        temp = a[i];
		j = i - 1;
        while (j >= 0 && a[j] > temp)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
        a[j + 1] = temp;
    }
}
template <class T>
void PrintArray(T *a, int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << "\n\n";
}
int main()
{
    int a[10],n,s;
	int i;
	cout<<"input the number of array:";
	cin>>n;
	cout<<"input the array:";
	for(i=0;i<n;i++)
	    cin>>a[i];
	cout<<"\nthe elements of the array before ascending:\n";
	PrintArray(a, n);
    cout<<"\ninput 1 to insertion sort:";
    cout<<"\ninput 2 to  bubble sort:";
    cout<<"\ninput 3 to  selection sort:\n";
    cin>>s;
    if(s==1)
	    InsertionSort(a,n);
    else if(s==2)
        bubble_sort(a,n);
    else if(s==3)
        selection_sort(a,n);
        else
            cout<<"\nvalid input not found";
    cout<<"\nthe elements of the array after ascending;\n";
	PrintArray(a,n);
}

