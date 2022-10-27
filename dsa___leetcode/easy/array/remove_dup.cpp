#include<iostream>
using namespace std;
    void removeDuplicates(int arr[],int n) 
    {
        if(n==0)
        {
            return;
        }
        int i=0;
        for(int j=1;j<n;j++)
        {
            if(arr[j]!=arr[i])
            {
                i++;
                arr[i]=arr[j];
            }
        }
    }
    void print(int a[],int n)
    {
	int i;
	for(i=0;i<n;i++)
        cout<<a[i]<<",";
    }   
    int main()
    {
        int a[]={1,1,2,2,2,3,3};
        int n=sizeof(a)/sizeof(int);
        removeDuplicates(a,n);
        print(a,n);
    }