/*6. Perform Stack operations using Linked List implementation.*/
#include<iostream>
using namespace std;
class IntSLLNode 
{
	
	public:
		IntSLLNode() 
		{
			next = 0;
		}
		IntSLLNode(int e1, IntSLLNode *ptr = 0) 
		{
			info = e1; next = ptr;
		}
	int info;
	IntSLLNode *next;
	
};
class IntSLList 
{	
	
	public:
		void display()
		{
			IntSLLNode *t;
			for(t=top;t!=0;t=t->next)
				cout<<t->info  <<  " ";
		}
		IntSLList()
		{
			top = 0;
		}
		~IntSLList();
		int isEmpty() 
		{
			return top == 0;
		}
		void push(int);
		int pop();
		private:
			IntSLLNode *top;
};

	IntSLList::~IntSLList() 
	{	
		for (IntSLLNode *p; !isEmpty(); ) 
		{
			p = top->next;
			delete top;
			top = p;
		}
	}
	void IntSLList::push(int el) 
	{
		top = new IntSLLNode(el,top);
	}
	int IntSLList::pop() 
	{
		int el = top->info;
		IntSLLNode *tmp = top;
		top = top->next;
		delete tmp;
		return el;
	}
	int main()
	{
		
		int i;
		IntSLList r;
		for(i=2;i<10;i++)
			{
				r.push(i);
			}
		cout<<"the stack is:";
		r.display();
		cout<< endl;
		int s;
		cout<<"a.input 1 to push:\n";
		cout<<"b.input 2 to pop:\n";
		cin>>s;
		if(s==1)
		{
			cout<<"enter number want to push:";
			int a;
			cin>>a;
			r.push(a);
			r.display();
		}
		else if(s==2)
		{
			r.pop();
			r.display();
		}
		else
		{
			cout<<"no valid entry:";
		}
	}
