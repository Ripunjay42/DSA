class Solution {
public:
    vector<int> sortedSquares(vector<int>& a) 
    {   
        int n=a.size();
        vector<int> res(n);
        unordered_map<int, int> m;
        int l=0,r=a.size()-1;
        for(int i=0;i<n;i++)
        {
            m[i]=pow(a[i],2);
        }
        for(int k=a.size()-1;k>=0;k--)
        {
            if(m[r]>m[l])
            {  
                res[k]=m[r];
                r--;
            }
            else
            {
                res[k]=m[l];
                l++;
            }
        }
        return res;
    }
};