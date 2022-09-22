/*9.Create and perform different operations on Double-ended Queues using Linked List
implementation.*/
#include<iostream>
using namespace std;
#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST
template<class T>
class DLLNode 
{
    public:
        DLLNode() 
        {
            next = prev = 0;
        }
        DLLNode(const T& el, DLLNode *n = 0, DLLNode *p = 0) 
        {
            info = el; next = n; prev = p;
        }
        int info;
        DLLNode<T> *next, *prev;
};
template<class T>
class Dqueue 
{
    public:
        void display()
        {
            DLLNode<T> *t;
            for(t=front;t!=0;t=t->next)
                cout<<t->info<<" ";
        }
        Dqueue() 
        {
            front =rear = 0;
        }
        void push_rear(int);
        int pop_rear();
        void push_front(int);
        int pop_front();
        protected:
        DLLNode<T> *front, *rear;
};
#endif
template<class T>
void Dqueue<T>::push_rear(int el) 
{
    if (rear != 0) 
    {
       rear = new DLLNode<T>(el,0,rear);
       rear->prev->next =rear;
    }
    else front =rear = new DLLNode<T>(el);
}
template<class T>
int Dqueue<T>::pop_rear() 
{
    int el =rear->info;
    if (front ==rear)  // if only one node in the list;
    {
        delete front;
        front =rear = 0;
    }
    else 
    { 
       rear =rear->prev;
        delete rear->next;
       rear->next = 0;
    }
    return el;
}
template<class T>
void Dqueue<T>::push_front(int el) 
{
    
		front = new DLLNode<T>(el,front,0);
		if (rear == 0)
			rear = front;

}
template<class T>
int Dqueue<T>::pop_front()
{
    int el=front->info;
    DLLNode<T> *tmp = front;
	if (front ==rear) // if only one node in the list;
			front =rear = 0;
	else front = front->next;
	delete tmp;
	return el;
}
 int main()
	{
		int i;
		Dqueue<int> r1;
		for(i=1;i<8;i++)
			{
				r1.push_rear(i);
			}
		cout<<"elements of the queue is :";
		r1.display();
		cout<<endl;
		int s;
		cout<<endl;
		cout<<"a.input 1 to insert at rear:\n";
		cout<<"b.input 2 to delete from rear:\n";
		cout<<"c.input 3 to  add to front :\n";
		cout<<"d.input 4 to delete from front:\n";
		cout<<":::>>>>>>>";
		cin>>s;
		if(s==1)
			{
				int a;
				cout<<"which element want to add:";
				cin>>a;
				r1.push_rear(a);
				r1.display();
			}
		else if(s==2)
			{
				r1.pop_rear();
				r1.display();
			}
		else if(s==3)
			{
				int b;
				cout<<"which element want to add:";
				cin>>b;
				r1.push_front(b);
                r1.display();
			}
        else if(s==4)
			{
				r1.pop_front();
				r1.display();
			}
        else
			{
				cout<<"valid entry not found!\n";
			}
		
	}
        
