class Solution {
public:
    void nextPermutation(vector<int>& v) 
    {
    int k=0;
    int l=0;
    int n=v.size();
    for(k=n-2;k>=0;k--)
    {
        if(v[k+1]>v[k])
        {
            break;
        }
    }
    if(k<=-1)
    {
        reverse(v.begin(),v.end());
    }
    else if(k>=0)
    {
        for(l=n-1;l>=0;l--)
        {
            if(v[l]>v[k])
            {
                break;
            }
        }
        swap(v[l],v[k]);
        reverse(v.begin()+k+1,v.end());
    }
    }
};