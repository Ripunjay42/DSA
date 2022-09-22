/*4. Implement Doubly Linked List using templates. Include functions for insertion, deletion and
search of a number, reverse the list.*/
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
class DLList 
{
    public:
        void display()
        {
            DLLNode<T> *t;
            for(t=head;t!=0;t=t->next)
                cout<<t->info<<" ";
        }
        DLList() 
        {
            head = tail = 0;
        }
        void addToTail(int);
        int deleteFromTail();
        bool search(int);
        void reverse();
        protected:
        DLLNode<T> *head, *tail;
};
#endif
template<class T>
void DLList<T>::addToTail(int el) 
{
    if (tail != 0) 
    {
        tail = new DLLNode<T>(el,0,tail);
        tail->prev->next = tail;
    }
    else head = tail = new DLLNode<T>(el);
}
template<class T>
int DLList<T>::deleteFromTail() 
{
    int el = tail->info;
    if (head == tail)  // if only one node in the list;
    {
        delete head;
        head = tail = 0;
    }
    else 
    { 
        tail = tail->prev;
        delete tail->next;
        tail->next = 0;
    }
    return el;
}
template<class T>
bool DLList<T>::search(int e1)
    {  
        DLLNode<T> *tmp = head; // Initialize current  
        while (tmp!= NULL)  
        {  
            if (tmp->info == e1)  
                return true;  
            tmp = tmp->next;  
        }  
        return false;  
    }
    template<class T>
    void DLList<T>::reverse()
        {
             DLLNode<T> *current = head;
        DLLNode<T> *prev = NULL,*next=NULL;
 
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
        head=prev;
        }

 int main()
	{
		int i;
		DLList<int> r1;
		for(i=1;i<8;i++)
			{
				r1.addToTail(i);
			}
		cout<<"the  1st list is :";
		r1.display();
		cout<<endl;
		int s;
		cout<<endl;
		cout<<"a.ipunt 1 to insert  an element to tail in 1st list:\n";
		cout<<"b.input 2 to delete from tail of 1st list:\n";
		cout<<"c.input 3 to search an element from 1st list:\n";
		cout<<"d.input 4 to reverse 1st list:\n";
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
				r1.deleteFromTail();
				r1.display();
			}
		else if(s==3)
			{
				int b;
				cout<<"which element want to search:";
				cin>>b;
				r1.search(b)? cout<<"element found\n" : cout<<"element not found\n";
			}
        else if (s==4)
            {
                cout<<"before reverse the list:";
                r1.display();
                cout<< endl;
                r1.reverse();
                cout<<"after reverse the list:";
                r1.display();
                
            }
        else
			{
				cout<<"valid entry not found!\n";
			}
		
	}
        
