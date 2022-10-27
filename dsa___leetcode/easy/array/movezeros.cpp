class Solution {
public:
    void moveZeroes(vector<int>& n)
    {
        int j=0;
        for(int i=0;i<n.size();i++)
        {
            if(n[i]!=0)
            {
                n[j++]=n[i];
            }
        }
        while(j<n.size())
        {
            n[j++]=0;
        } 
    }
};