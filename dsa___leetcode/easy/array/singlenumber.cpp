class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int n=nums.size();
        unordered_map<int, int> m;
        for(int i=0;i<n;i++)
        {
            m[nums[i]]++;
        }
        int k;
        for(auto x:m)
        {
            if(x.second==1)
            {
                k=x.first;
                break;
            }
        }
        return k;
    }
};