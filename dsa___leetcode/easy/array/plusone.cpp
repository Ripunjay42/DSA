class Solution {
public:
    vector<int> plusOne(vector<int>& a) 
    {
        int n=a.size();
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]<9)
            {
                a[i]++;
                return a;
            }
            else
                a[i]=0;
        }
        if(a[0]==0)
        {
             a.push_back(0);
             a[0] = 1;
             return a;
        }
        return a;
    }
};