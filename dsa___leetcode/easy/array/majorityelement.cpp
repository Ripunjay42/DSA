class Solution {
public:
    int majorityElement(vector<int>& a) 
    {
        int b;
        int n=a.size();
        int max=n/2;
        unordered_map<int, int> m;
        for(int i:a)
        {
            m[i]++;
        }
        int maxval;
        for(auto x:m)
        {
            if(x.second>max)
            maxval=x.first;
        }
        return maxval;
    }
};