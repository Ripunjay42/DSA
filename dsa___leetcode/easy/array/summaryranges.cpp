class Solution 
{
public:
    vector<string> summaryRanges(vector<int>& a) 
    {
        int n=a.size();
        vector<string> res;
        if(n==0) return res;
        for(int i=0;i<n;)
        {
            int s = i;
            int e = i;
            while(e+1<n && a[e+1]==a[e]+1)
            {
                e++;
            }
            if(e>s) 
                res.push_back(to_string(a[s])+"->"+to_string(a[e]));
            else
                res.push_back(to_string(a[s]));
            i=e+1;
        }
        return res;
    }
};