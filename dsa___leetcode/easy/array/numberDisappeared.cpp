class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> ans;
        sort(begin(nums), end(nums));
        for(int i = 1; i<=n; i++)
        { 
            if(!binary_search(begin(nums), end(nums), i))
                ans.push_back(i);
        }
        return ans;    
    }
};