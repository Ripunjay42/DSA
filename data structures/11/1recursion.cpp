#include<iostream>
using namespace std;
int factorial(int n)
{
	if(n==0)
		return(1);
	else return(n*factorial(n-1));
}
int factor(int n,int i)
{	
	if(i<=n)
	{
		if(n%i==0)
		{
			cout<<i<<" ";
		}
	factor(n,i+1);
	}
}
int main()
{
	int a;
	cout<<"\nenter the number:";
	cin>>a;
	cout<<"\nfactorial is:"<<factorial(a)<<endl;
	cout<<"factors are\n";
	factor(a,1);
}
