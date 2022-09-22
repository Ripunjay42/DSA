#include<iostream>
using namespace std;
int factorial(int n)
{
	int i,f=1;
	for(i=n;i>0;i--)
		f=f*i;
	return(f);
}
int factor(int n)
{	
	int i;
	for(i=1;i<=n;i++)
		if(n%i==0)
		{
			cout<<i<<endl;
		}
		return 0;
}
int main()
{
	int a;
	cout<<"\nenter the number:";
	cin>>a;
	cout<<"\nfactorial is:"<<factorial(a)<<endl;
	cout<<"factors are\n";
	factor(a);
}
