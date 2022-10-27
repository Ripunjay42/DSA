class Solution {
public:
    int maxProfit(vector<int>& p) 
    {
        int n=p.size();
        int min=p[0];
        int profit=0;
        int max_profit=0;
        for(int i=0;i<n;i++)
        {
            if(min>p[i])
            {
                min=p[i];
            }
            profit=p[i]-min;
            if(max_profit<profit)
            {
                max_profit=profit;
            }
        }
        return max_profit;
        
    }
};