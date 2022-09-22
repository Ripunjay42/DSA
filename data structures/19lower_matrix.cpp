#include<iostream>
using namespace std;
class matrix
{
	private:
	double a[5][5];
	int r,c;
	int  n=0;
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
	cin>>r;
	cout<<"input elements:";
	for(i=0;i<r;i++)
		{for(j=0;j<r;j++)
			{
				cin>>a[i][j];
				n++;
			}
			
		}
}
void convert_lower()
{
	int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < r; j++)
        {
            if (i<j)
            {
                cout << "0" << " ";
            }
            else
               cout << a[i][j] << " ";
			   n++;
        }
        cout << endl;
    }
}
void  one_lower()
{
	int i,j,compact[10];
	int n=0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<r;j++)
		{
			if(i<j && a[i][j]!=0)
		  		{
					  cout<<">>>>NOT A lower MATRIX<<<<";
					  exit(0);
				}
			if(i>=j)
				{
					compact[i]=a[i][j];
					n=n+1;
				}
			
		}
	}
	cout<<"\nIn Diagonal Form :";
  	for(i=0;i<n;i++)
	  {
    	cout << compact[i] << " ";
  	  }
}
};
int main()
{
	matrix a(5);
	cout<<"creat a matrix:\n";
	a.read_matrix();
	cout<<"in lower triangular form:\n";
	a.convert_lower();
	a.one_lower();
}