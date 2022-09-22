#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void ReverseSUQ(stack<int>& s) 
{
    queue<int> q;
    while (!s.empty()) 
    {
        q.push(s.top());
        s.pop();
    }
    while (!q.empty()) 
    {
        s.push(q.front());
        q.pop();
    }
}
int main()
{
    int n;
    stack<int> s;
    cout << "Enter number of elements: ";
    cin >> n;
    cout<<"input elements: ";
    for (int i=0;i<n;i++) 
    {
        int a;
        cin >> a;
        s.push(a);
    }
    // cout<<"stack is :";
    // for (int i = 0; i < n; i++) 
    // {
    //     cout << s.top() << " ";
    //     s.pop();
    // }
    ReverseSUQ(s);
    cout<<"\nafter reverse the stack:";
    for (int i = 0; i < n; i++) 
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}