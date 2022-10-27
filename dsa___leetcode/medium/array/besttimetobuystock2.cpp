class solution
{
    public:
        int maxProfit(vector<int>& p)
        {
            int n=p.size();
            int net_profit=0
            for(int i=1;i<n;i++)
            {
                if(p[i]>p[i-1])
                {
                    net_profit+=p[i]-p[i-1];
                }
            }
            return net_profit;
        }
}