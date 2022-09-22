#include<iostream>
using namespace std;
class matrix
{
	private:
	double a[5][5];
	int r,c;
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
			}
			
		}
	}
void one_diagonal()
{
	int i,j,compact[10];
	for(i=0;i<r;i++)
	{
		for(j=0;j<r;j++)
		{
			if(i!=j && a[i][j]!=0)
		  		{
					  cout<<">>>>NOT A DIAGONAL MATRIX<<<<";
					  exit(0);
				}
			if(i==j)
				{
					compact[i]=a[i][j];
				}
			
		}
	}
	cout<<"\nIn Diagonal Form :";
  	for(i=0;i<r;i++)
	  {
    	cout << compact[i] << " ";
  	  }
	cout<<"\nDisplaying the Original Matrix";
  	for(i=0;i<r;i++)
  	{
		cout << endl;
		for(j=0;j<r;j++)
		{
			if(i == j)
			{ 
				cout << compact[i] << " ";
			}
			else
			{
				cout << "0 ";
			}
		}
	}
}
};
int main()
{
	matrix a(5);
	cout<<"creat a diagonale matrix:\n";
	a.read_matrix();
	a.one_diagonal();
}