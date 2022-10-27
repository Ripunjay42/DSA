class Solution {
public:
    int missingNumber(vector<int>& a) 
    {
        int n=a.size();
        int sum=0;
        int total=n*(n+1)/2;
        for(int i:a)
        {
            sum+=i;
        }
        return total-sum;
    }
};