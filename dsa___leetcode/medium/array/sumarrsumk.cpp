class Solution {
public:
    int subarraySum(vector<int>& a, int k) 
    {   
        int n=a.size();
        int  p[n];
        p[0]=a[0];
        for(int i=1;i<n;i++)
        {
            p[i]=a[i]+p[i-1];
        }
        unordered_map<int, int> m;
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(p[i]==k)
                c++;
            if(m.find(p[i]-k)!=m.end())
            {
                c+=m[p[i]-k];
            }
            m[p[i]]++;
        }
    return c;
    }
};