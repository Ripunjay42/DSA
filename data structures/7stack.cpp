/*7.Perform Stack operations using Array implementation. Use Templates.*/
#include<iostream>
using namespace std;
template<class T>
class stack
{
    private: 
        T *arr;
        int size;
        int top;
    public: 
    stack(int s=10)
        {
            arr=new T[s];
            size=s;
            top=-1;
        }
    int is_empty()
        {
            if(top==-1) return 1;
            else return 0;
        }
    int is_full()
        {
            if(top==size-1) return 1;
            else return 0;
        }
    int push(T item)
        {
            if(!is_full())
            {
                top++;
                arr[top]=item;
                return 1;
            }
            else return 0;
        }
    int pop(T &item)
        {
            if(!is_empty())
            {
                item=arr[top];
                top--;
                return 1;
            }
            else return 0;
        }
    void display() 
        {
            
                for(int i=top; i>=0; i--)
                    cout<<arr[i]<<" ";
             cout<<endl;
        }

};
int main()
{
    stack <int> r;
    int i;
    for(i=5;i<9;i++)
    {
        r.push(i);
    }
    cout<<"stack is:";
    r.display();
    cout<<endl;
    int s;
    cout<<"a.input 1 to push a number:\n";
    cout<<"b.input 2 to pop a number:\n";
    cin>>s;
    if(s==1)
        {
            int a;
            cout<<"enter number to push:";
            cin>>a;
            r.push(a);
            r.display();
        }
    else if(s==2)
        {
            int b;
            cout<<"enter top element of the stack to pop:";
            cin>>b;
            r.pop(b);
            r.display();
        }
    else
    	{
            cout<<"valid entry not found:\n";
    	}
    
}