class Solution {
public:
    int fib(int n) 
    {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        int t1=0;
        int t2=1;
        int t3;
        for(int i=n;i>1;i--)
        {
            t3=t1+t2;
            t1=t2;
            t2=t3;
        }
        return t3;
    }
};