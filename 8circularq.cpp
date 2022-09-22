/*8.Perform Queues operations using Circular Array implementation. Use Templates*/
#include<iostream>
using namespace std;
#ifndef ARRAY_QUEUE
#define ARRAY_QUEUE
template<class T,int size = 100>
class ArrayQueue 
   {
    public:
        ArrayQueue() 
        {
            first = last = -1;
        }
        void enqueue(T);
        T dequeue();
        void display();
        bool isFull() 
        {
            return first == 0 && last == size-1 || first == last + 1;
        }
        bool isEmpty() 
        {
            return first == -1;
        }
    private:
        int first, last;
        T storage[size];
    };
    template<class T, int size>
    void ArrayQueue<T,size>::enqueue(T el) 
    {
        if (!isFull())
            if (last == size-1 || last == -1) 
            {
                storage[0] = el;
                last = 0;
                if (first == -1)
                    first = 0;
            }
            else storage[++last] = el;
        else cout << "Full queue.\n";
    }
    template<class T, int size>
    T ArrayQueue<T,size>::dequeue() 
    {
        T tmp;
        tmp = storage[first];
        if (first == last)
            last = first = -1;
        else if (first == size-1)
            first = 0;
        else first++;
            return tmp;
    }
    template<class T, int size>
    void ArrayQueue<T,size>:: display()
    {
        if (first == -1) 
        { 
            cout<<"\nQueue is Empty"; 
            return; 
        }  
        if (last>= first) 
        { 
            for (int i = first; i <= last; i++) 
                cout<<storage[i]<<" "; 
        } 
        else
        { 
            for (int i = first; i < size; i++) 
                cout<<storage[i]<<" "; 
    
            for (int i = 0; i <= last; i++) 
                cout<<storage[i]<<" "; 
        } 
    }
    #endif
    int main()
    {
        int i;
        ArrayQueue<int> r;
        for(i=1;i<8;i++)
        {
            r.enqueue(i);
        }
        cout<<"elements of the queue:";
        r.display();
        cout<<endl;
        int s;
        cout<<"1.input 1 to enqueue:\n";
        cout<<"2.input 2 to dequeue:\n";
        cin>>s;
        if(s==1)
        {
            int a;
            cout<<"enter the element to enqueue:";
            cin>>a;
            r.enqueue(a);
            r.display();
        }
        else if(s==2)
        {
            r.dequeue();
            r.display();
        }
        else 
        {
            cout<<"valid entry not found!";
        }
    }