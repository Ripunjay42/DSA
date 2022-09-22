#include<iostream>
using namespace std;
int fibo_ite(int n)
{
	int t1,t2,t3;
	if(n==1)	
		return(0);
	if(n==2)
		return(1);
	t1=0;
	t2=1;
	for(   ;n>2;n--)	
	{
		t3=t1+t2;
		t1=t2;
		t2=t3;
	}
	return(t3);
}
int fibo_rec(int n)
{
	if(n==1)
	   return(0);
	if(n==2)
	   return(1);
	else return(fibo_rec(n-1)+fibo_rec(n-2));
}
int main()
{
    int a;
    cout<<"enter the no of term:";
    cin>>a;
    int i;
    cout<<"\n1.input 1 to use recursion:";
    cout<<"\n2.input 2 to use iteration:\n";
    cin>>i;
    if(i==1)
    {
        cout<<"the number is:"<<fibo_rec(a)<<endl;
    }
    else if(i==2)
    {
         cout<<"the number is:"<<fibo_ite(a)<<endl;
    }
    else
    {
        cout<<"invalid input!";
    }
}

