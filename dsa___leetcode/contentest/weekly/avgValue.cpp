class Solution {
public:
    int averageValue(vector<int>& nums) 
    {
        int n=nums.size();
        int count=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0 && nums[i]%3==0)
            {
                sum+=nums[i];
                count++;
            }
        }
        if(sum>0)
        {
            int avg=sum/count;
            return avg;
        }
        else
            return 0;
    }
};