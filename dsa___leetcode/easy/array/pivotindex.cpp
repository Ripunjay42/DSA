class Solution {
public:
    int pivotIndex(vector<int>& n) 
    {
        int  rightsum=accumulate(n.begin(), n.end(), 0);
        int leftsum=0;
        for(int i=0;i<n.size();i++)
        {
            rightsum-=n[i];
            if(rightsum==leftsum)
                return i;
            leftsum+=n[i];
        }
        return -1;
    }
};