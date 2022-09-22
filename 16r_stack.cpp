#include <bits/stdc++.h>
#include<iostream>
using namespace std;
void transfer(stack<int> &s1,stack<int> &s2, int n)
{
    for (int i = 0; i < n; i++) 
    {
        int temp = s1.top();
        s1.pop();
        s2.push(temp);
    }
}
void reverse(stack<int>& s,int n)
{
    stack<int> s2;
    for (int i = 0; i < n; i++) 
    {
        int x = s.top();
        s.pop();
        transfer(s, s2, n - i - 1);
        s.push(x);
        transfer(s2, s, n - i - 1);
    }
}
int main()
{
     int n;
    stack<int> s;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "input elements: ";
    for (int i=0;i<n;i++) 
    {
        int a;
        cin >> a;
        s.push(a);
    }
    // cout<<"stack is:";
    // for(int i = 0; i < n; i++) 
    // {
    //     cout << s.top() << " ";
    //     s.pop();
    // }
    reverse(s, n);
    cout<<"after reverse the stack:";
    for (int i = 0; i < n; i++) 
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}