#include<iostream>
using namespace std;
class matrix
{
	private:
	double a[5][5];
	int r,c;
	int len;
	public:
	matrix()
	{
		r=c=0;
	}
	matrix(int x)
	{
		r=x;
		c=x;
	}
	matrix(int x,int y)
	{
		r=x;
		c=y;
	}
void read_matrix()
{
	int i,j;
	cout<<"enter dimenton:";
	cin>>r>>c;
	cout<<"input elements:";
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			cin>>a[i][j];
	}
}
void display_matrix()
{
	int i,j;
	cout<<"\n elements of the matrix are:\n";
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
			cout<<a[i][j]<<"   ";
			cout<<endl;
			cout<<endl;
	}
}
matrix convert_nonzero()
{
    int size = 0;
    matrix y(r,c);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            {
                if (a[i][j] != 0)
                {
                    size++;
                }
            }
    }
    y.r = size;
    y.c = 3;
    int k = 0;
    for (int i = 0; i < r; i++)
       { 
           for (int j = 0; j < c; j++)
           {
                if (a[i][j] != 0)
                {
                    y.a[k][0] = i+1;
                    y.a[k][1] = j+1;
                    y.a[k][2] = a[i][j];
                    k++;
                }
           }
        }
    return y;
}
// void insert(int val)
// {
// 	a[len][0]=r;
// 	a[len][1]=c;
// 	a[len][2]=val;
// 	len++;
// }
// matrix convert_sparse()
// {
// 	matrix y(r,c);
// 	for(int i=0;i<r;i++)
// 	{
// 		for(int j=0;j<c;j++)
// 		{
// 			if(a[i][j]>0)
// 			{
// 				insert(a[i][j]);
// 			}
// 			display_matrix()
// 		}
// 	}
// 	return y;
// }
};
int main()
{
    matrix a(5),b,c;
    cout<<"\nenter the 1st matrix:\n";
	a.read_matrix();
	a.display_matrix();
    b=a.convert_nonzero();
    cout<<"Triplet Representation : "<<endl;
    b.display_matrix();
	// c=b.convert_sparse();
	// c.display_matrix();
    return 0;
}