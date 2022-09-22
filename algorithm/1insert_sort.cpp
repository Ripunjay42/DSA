#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
int insert_sort(int a[] , int n)
{
    int i, j,temp;
	int count=0;
    for (int i = 1; i < n; ++i)
	{
        temp = a[i];
		j = i - 1;
        while (j >= 0 && a[j] > temp)
		{
			a[j + 1] = a[j];
			j = j - 1;
           count++;
		}
        a[j + 1] = temp;
        if(temp>a[j])
        {
           count++;
        }
    }
    return count;
}
void print(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
}
int main()
{
    ofstream myfile;
    myfile.open ("i.txt");
    for(int i=0;i<100;i++)
    {
        int n=30+rand()%970;
        int a[n];
        for(int j=0;j<n;j++)
            a[j]=rand()%100;
        n=sizeof(a) / sizeof(a[0]);
        int count = insert_sort( a, n);
        myfile <<n<<" - "<<count<<endl;
        cout<<"\nthe elements of the array after ascending=>>>>>>";
        print(a,n);
        cout<<endl;
        cout<<endl;
        cout<<"Number of comparisions=>>>>>>"<<count<<endl;
    }
    myfile.close();
    return 0;
}
 /*int main()
 {
     int arr[] = { 5,7,8,6,4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"\nthe elements of the array before ascending=>>>>>>";
    print(arr,n);
    int count=insert_sort(arr, n);
    cout << "Sorted array is=>>>>>";
    print(arr, n);
    cout<<"Number of comparisions=>>>>>>"<<count<<endl;
 }*/

