class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==val)
            {
                nums[i]=nums[n-1];
                i--;
                n--;
            }
        }
        return n;
    }
};