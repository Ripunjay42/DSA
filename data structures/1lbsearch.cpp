/*1. Write a program to search an element from a list. Give user the option to perform Linear or
Binary search. Use Template functions.*/
#include<iostream>
using namespace std;
template <class T>
int l_search(T *a, T item, int n)
{
    int i;
    for(i=0;i<n;i++)
        if(a[i]==item)
            return i;
        return -1;
}
template <class T>
int b_search(T *a,T item,int n)
{
	int start = 0;
	int end = n-1;
	while(start<=end)
	{
		int mid = (start+end)/2;
		if(a[mid]==item)	
			return mid;
		else if(a[mid]<item)	
			start = mid + 1;
		else	
			end = mid - 1;
	}
	return -1;
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

    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n = sizeof(arr) / sizeof(int);

    cout << "Array : " << endl;
    PrintArray(arr, n);
    
    int item,index,s;
    cout<<"Enter value you want to Search: ";
    cin>>item;
    cout<<"enter 1 to linear search and 2 to binary search:";
    cin>>s;
    {
        if(s==1)
            cout<<"\nposition of the number:"<<l_search(arr,item,n);
        else if(s==2)
            cout<<"\nposition of the number:"<<b_search(arr,item,n);
        else
            cout<<"\no valid entry found";
    }
}
