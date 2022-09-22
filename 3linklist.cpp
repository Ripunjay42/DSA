/*3. Implement Linked List using templates. Include functions for insertion, deletion and search of a number, 
reverse the list and concatenate two linked lists (include a function and also overload operator +).*/
#include<iostream>
using namespace std;
#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST
template<class T>
class IntSLLNode 
{
	
	public:
		IntSLLNode() 
		{
			next = 0;
		}
		IntSLLNode(int e1, IntSLLNode<T> *ptr = 0) 
		{
			info = e1; next = ptr;
		}
	int info;
	IntSLLNode<T> *next;
	
};
template<class T>
class IntSLList 
{	
	
	public:
		void display()
		{
			IntSLLNode<T> *t;
			for(t=head;t!=0;t=t->next)
				cout<<t->info  <<  " ";
		}
		IntSLList()
		{
			head = tail = 0;
		}
		~IntSLList();
		int isEmpty() 
		{
			return head == 0;
		}
		void addToHead(int);
		void addToTail(int);
		int deleteFromHead(); // delete the head and return its info;
		int deleteFromTail(); // delete the tail and return its info;
		bool search(int);
		void reverse();
		void operator + (const IntSLList<T> &B);
		private:
			IntSLLNode<T> *head, *tail;
};
#endif
    template<class T>
	IntSLList<T>::~IntSLList() 
	{	
		for (IntSLLNode<T> *p; !isEmpty(); ) 
		{
			p = head->next;
			delete head;
			head = p;
		}
	}
    template<class T>
	void IntSLList<T>::addToHead(int el) 
	{
		head = new IntSLLNode<T>(el,head);
		if (tail == 0)
			tail = head;
	}

    template<class T>
	void IntSLList<T>::addToTail(int el) 
	{
		if (tail != 0) 
		{ 
			tail->next = new IntSLLNode<T>(el);
			tail = tail->next;
		}
		else head = tail = new IntSLLNode<T>(el);
	}
    template<class T>
	int IntSLList<T>::deleteFromHead() 
	{
		int el = head->info;
		IntSLLNode<T> *tmp = head;
		if (head == tail) // if only one node in the list;
			head = tail = 0;
		else head = head->next;
		delete tmp;
		return el;
	}
    template<class T>
	int IntSLList<T>::deleteFromTail()
 	{
		int el = tail->info;
		if (head == tail) 
		{ 
			delete head;
			head = tail = 0;
		}
		else 
		{ // if more than one node in the list,
			IntSLLNode<T> *tmp; // find the predecessor of tail;
			for (tmp = head; tmp->next != tail; tmp = tmp->next);
				delete tail;
				tail = tmp; // the predecessor of tail becomes tail;
				tail->next = 0;
		}
			return el;
    }
    template<class T>
    bool IntSLList<T>::search(int e1)
    {  
        IntSLLNode<T> *tmp = head; // Initialize current  
        while (tmp!= NULL)  
        {  
            if (tmp->info == e1)  
                return true;  
            tmp = tmp->next;  
        }  
        return false;  
    }
	template<class T> 
    void IntSLList<T>::reverse()
    {
        // Initialize current, previous and
        // next pointers
        IntSLLNode<T> *current = head;
        IntSLLNode<T> *prev = NULL,*next=NULL;
 
        while (current != NULL) 
			{
            // Store next
            next = current->next;
 
            // Reverse current node's pointer
            current->next = prev;
 
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }
	template<class T>
	void IntSLList<T> :: operator +(const IntSLList<T> &B)
	{
		IntSLLNode<T> *X, *Y, *Union;	//two node pointers
		
		X = head;	//X is the head of the caller LList
		Y = B.head;	//Y is the head of the passed LList
		
		while (X->next != NULL)	//While we are not at the end of the caller
		{
			X = X->next;	//Continue to the successor
		}
		
		X->next = Y;	//set the end's link to the start of the passed LList
		Union = X;	//union points to where they were 
		
	}
    int main()
	{
		int i;
		IntSLList<int> r1,r2,r3;
		for(i=1;i<8;i++)
			{
				r1.addToTail(i);
			}
		cout<<"the  1st list is :";
		r1.display();
		cout<<endl;
		for(i=8;i<15;i++)
			{
				r2.addToTail(i);
			}
		cout<<"the  2st list is :";
		r2.display();
		cout<<endl;
		int s;
		cout<<endl;
		cout<<"a.ipunt 1 to insert  an element to tail in 1st list:\n";
		cout<<"b.input 2 to delete from head of 1st list:\n";
		cout<<"c.input 3 to search an element from 1st list:\n";
		cout<<"d.input 4 to reverse 1st list:\n";
		cout<<"e.input 5 to concatenate 1st and 2nd list:\n";
		cout<<":::>>>>>>>";
		cin>>s;
		if(s==1)
			{
				int a;
				cout<<"which element want to add:";
				cin>>a;
				r1.addToTail(a);
				r1.display();
			}
		else if(s==2)
			{
				r1.deleteFromHead();
				r1.display();
			}
		else if(s==3)
			{
				int b;
				cout<<"which element want to search:";
				cin>>b;
				r1.search(b)? cout<<"element found\n" : cout<<"element not found\n";
			}
		else if(s==4)
			{
				cout<<"before reverse the list:";
				r1.display();
				cout << endl;
       			r1.reverse();
				cout<<"after reverse the list:";
				r1.display();
			}
		else if(s==5)
			{
				r1+r2;
				cout<<"concatenated list is:"; 
				r1.display();
			}
		else
			{
				cout<<"valid entry not found!\n";
			}
		
	}
        