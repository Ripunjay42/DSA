#include<iostream>
#include<fstream>
using namespace std;
int merge(int a[], int l, int m, int r)
{
    int count=0;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            a[k] = L[i];
            i++;
        }
        else 
        {
            a[k] = R[j];
            j++;
        }
        k++;
        count++;
    }
    while (i < n1) 
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) 
    {
        a[k] = R[j];
        j++;
        k++;
    }
    return count;
}
int merge_sort(int a[],int l,int r)
{
    int count=0;
    if(l<r)
    {
        int m =l+ (r-l)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,r);
        count=merge(a,l,m,r);
    }
    return count;
}
void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
/*int main()
{
    ofstream myfile;
    myfile.open ("m.txt");
    for(int i=0;i<100;i++)
    {
        int n=30+rand()%970;
        int a[n];
        for(int j=0;j<n;j++)
            a[j]=rand()%100;
        n=sizeof(a) / sizeof(a[0]);
        int count = merge_sort( a, 0, n-1);
        myfile <<n<<" - "<<count<<endl;
        /*cout<<"\nthe elements of the array after ascending=>>>>>>";
        print(a,n);
        cout<<endl;
        cout<<endl;
        cout<<"Number of comparisions=>>>>>>"<<count<<endl;
    }
    myfile.close();
    return 0;
}*/
int main()
 {
    int arr[] = { 6,7,9,2,4,1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"\nthe elements of the array before ascending=>>>>>>";
    print(arr,n);
    int count=merge_sort(arr,0,n-1);
    cout << "Sorted array is=>>>>>";
    print(arr, n);
    cout<<"Number of comparisions=>>>>>>"<<count<<endl;
 }