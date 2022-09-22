#include <cstdlib>
#include <time.h>
#include<iostream>
using namespace std;
void swap(int* a,int* b)
{
    
    int t = *a;
    *a = *b;
    *b = t;
}
int partition (int arr[], int p, int r)
{
    int count=0;
    int pivot = arr[r];    
    int i = (p - 1);  
    for (int j = p; j <= r- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;   
            swap(&arr[i], &arr[j]);
            count ++;
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return (i + 1);
}
int partition_r(int arr[], int p, int r)
{
    srand(time(NULL));
    int random = p + rand() % (r - p);
    swap(arr[random], arr[r]);
 
    return partition(arr, p, r);
}
int  quickSort(int arr[], int p, int r)
{
    int count =0;
    if (p < r)
    {
        int q = partition_r(arr, p, r);
        count =count+(r-p-1);
        quickSort(arr, p, q - 1);
        quickSort(arr, q + 1, r);
    }
    return count;
}
void print(int arr[],int n)
{
	int i;
	for(i=0;i<n;i++)
		cout<<arr[i]<<" ";
}
/*int main()
{
    int n;
    cout<<"enter the size of the array:";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        a[i]=rand()%100;
    }
    n=sizeof(a) / sizeof(a[0]);
    cout<<"\nthe elements of the array before ascending=>>>>>>";
    print(a,n);
    int count=quickSort( a, 0, n-1);
    cout<<"\nthe elements of the array after ascending=>>>>>>";
    print(a,n);
    cout<<endl;
    cout<<"Number of comparisions=>>>>>>"<<count<<endl;
}*/
int main()
{
    int arr[] = { 6, 7,5,2,8,9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"\nthe elements of the array before ascending=>>>>>>";
    print(arr,n);
    int count=quickSort(arr,0, n-1);
    cout << "Sorted array is=>>>>>";
    print(arr, n);
    cout<<"Number of comparisions=>>>>>>"<<count<<endl;

}
