class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxn = INT_MIN;
        int sum=0;
        for(int i =0 ; i< nums.size();i++)
        {
            sum = sum + nums[i];
            maxn = max(maxn , sum);

            if(sum<0) sum=0;
        }

        return maxn;
    }
};