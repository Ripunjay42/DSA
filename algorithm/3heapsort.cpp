#include <iostream>
using namespace std;
void swap(int* a,int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int heapify(int arr[], int n, int i)
{
    int count =0;
    int largest = i;
    int l = 2 * i + 1; 
    int r = 2 * i + 2; 
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) 
    {
        count ++;
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
    return count;

}
int heapSort(int arr[], int n)
{
    int count=0;
    for (int i = n / 2 - 1;i >= 0;i--)
        heapify(arr, n, i);
    for (int i = n - 1;i > 0;i--) 
    {
        swap(arr[0], arr[i]);
        count+=heapify(arr, i, 0);
    }
    return count;
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{
    int arr[] = { 67, 43, 32, 8, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"\nthe elements of the array before ascending=>>>>>>";
    printArray(arr,n);
    int count=heapSort(arr, n);
    cout << "Sorted array is=>>>>>";
    printArray(arr, n);
    cout<<"Number of comparisions=>>>>>>"<<count<<endl;

}