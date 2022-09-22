/*5. Implement Circular Linked List using templates. Include functions for insertion, deletion and
search of a number, reverse the list.*/
#include<iostream>
using namespace std;

template<class T>
class Node
{
    private:
        T info;
        Node<T>* next;
        template<typename U>friend class LinkedList;
    public:
        Node()
        {
            this->next = NULL;
        }
};

template<class T>
class LinkedList
{
    private:
        Node<T>* head;
    public:
        LinkedList()
        {
            this->head = NULL;
        }
        void addToTail(T item)
        {
            Node<T>* node = new Node<T>[1];
            node->info = item;
            if(head == NULL)
            {
                head = node;
                head->next = node;
                return;
            }
            Node<T>* temp = head;
            while(temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = node;
            node->next = head;
        }
        void addToHead(T item)
        {
            Node<T>* node = new Node<T>[1];
            node->info = item;
            if(head == NULL)
            {
                head = node;
                node->next = head;
                return;
            }
            node->next = head;
            Node<T>*temp = head;
            while(temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = node;
            head = node;
        }
         int length()
         {
            if(head == NULL) return 0;
            int len = 1;
            Node<int>* temp = head;
            while(temp->next != head)
            {
                len++;
                temp = temp->next;
            }
            return len;
        }
        void displayAll()
        {
            if(head == NULL)
            {
                cout<<"linked list is empty"<<endl;
                return;
            
            }
            Node<T>* temp = head;
            while(true)
            {
                cout<<temp->info<<"  ";
                temp = temp->next;
                if(temp==head) break;
            }
            cout<<endl;
        }
       void removeFromTail()
       {
            if(head == NULL)
            {
                cout<<"linked list is empty !"<<endl;
                return;
            }

            if(length() == 1)
            {
                removeFromHead();
                return;
            }

            Node<T>* temp = head;
            while(temp->next != head)
            {
                if(temp->next->next == head)
                {
                    temp->next = head;
                    break;
                }
                temp = temp->next;
            }
            
        }
        void removeFromHead()
        {
            if(head == NULL)
            {
                cout<<"linked list is empty !"<<endl;
                return;
            }
            if(length() == 1)
            {
                head = NULL;
                return;
            }
            Node<T>* temp = head;
            while(temp->next != head)
            {
                temp = temp->next;
            }
            head = head->next;
            temp->next = head;
        }
        bool search(T item)
        {
            Node<T> *tmp = head; // Initialize current  
            while (tmp!= head)  
            {  
                if (tmp->info == item)  
                    return true;  
                tmp = tmp->next;  
            }  
            return false;  
        }
        void reverse()
        {
            Node<T> *current = head;
            Node<T> *prev = head,*temp=head;
            current=current->next;
            temp=temp->next->next;
            while (current != head) 
			{
                
                current->next = prev;
                prev=current;
                current = temp;
                temp=temp->next;
                
            }
            head = prev;
            current->next=head;
        }
};

int main()
{
    int i;
		LinkedList<int> r1;
		for(i=1;i<8;i++)
			{
				r1.addToTail(i);
			}
		cout<<"the  1st list is :";
		r1.displayAll();
		cout<<endl;
		int s;
		cout<<endl;
		cout<<"a.input 1 to insert  an element to tail of list:\n";
		cout<<"b.input 2 to delete from head of list:\n";
		cout<<"c.input 3 to search an element from list:\n";
		cout<<"d.input 4 to reverse list:\n";
		cout<<":::>>>>>>>";
		cin>>s;
		if(s==1)
			{
				int a;
				cout<<"which element want to add:";
				cin>>a;
				r1.addToTail(a);
				r1.displayAll();
			}
		else if(s==2)
			{
				r1.removeFromHead();
				r1.displayAll();
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
				r1.displayAll();
				cout << endl;
       			r1.reverse();
				cout<<"after reverse the list:";
				r1.displayAll();
			}
        else
        {
            cout<<"valid entry not found!";
        }
        
}