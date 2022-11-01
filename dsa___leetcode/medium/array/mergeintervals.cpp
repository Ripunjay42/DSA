class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interv) 
    {
        sort(interv.begin(), interv.end());
        int n=interv.size();
        vector<vector<int>> res;
        res.push_back(interv[0]);
        for(int i=1;i<n;i++)
        {
            int m=res.size()-1;
            if(res[m][1]>=interv[i][0])
            {
                res[m][1]=max(res[m][1], interv[i][1]);
            }
            else
            {
                res.push_back(interv[i]);
            }
        }
        return res;
    }
};