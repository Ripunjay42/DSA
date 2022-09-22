#include<iostream>
using namespace std;
int gcd_rec(int a,int b)
{
	int t;
	if(a<b)
	{
		t=a;
		a=b;
		b=t;
	}
	if(a%b==0)
		return(b);
	else return(gcd_rec(b,a%b));
}
int gcd_ite(int a,int b)
{
	int t;
	if(a<b)
	{
		t=a;
		a=b;
		b=t;
	}
	while(a%b!=0)
	{
		t=a;
		a=b;
		b=t%b;
	}
	return(b);
}
int main()
{
	int a,b;
	cout<<"enter the 1st number:";
	cin>>a;
	cout<<"\nenter the 2nd number:";
	cin>>b;
	int i;
	cout<<"\n1.input 1 for recursive way:";
	cout<<"\n2.input 2 for non-recursive way:";
	cin>>i;
	if(i==1)
	{
		cout<<"gcd of the numbers is:"<<gcd_rec(a,b)<<endl;
	}
	else if(i==2)
	{
		cout<<"gcd of the numbers is:"<<gcd_ite(a,b)<<endl;
	}
	else
	{
		cout<<"no valid entry found!"<<endl;
	}


}