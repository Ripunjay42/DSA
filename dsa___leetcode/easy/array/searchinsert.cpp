class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int n=nums.size();
        int l=0;
        int h=n-1;
        while(l<h)
        {
            int m=(l+h)/2;
            if(nums[m]==target) 
                return m;
            else if(target<nums[m])
                h=m-1;
            else
                l=m+1;
        }
        if(nums[l]<target)
            return l+1;
        else
            return l;
    }
};