class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) 
    {
        int r=mat.size();
        int c=mat[0].size();
        int left=0, right=c-1, bottom=r-1, top=0;
        int dir=1;
        vector<int> res;
        while(left<=right && top<=bottom)
        {
            if(dir==1)
            {
                for(int i=left;i<=right;i++)
                {
                    res.push_back(mat[top][i]);
                }
                dir=2;
                top++;
            }
            else if(dir==2)
            {
                for(int i=top;i<=bottom;i++)
                {
                    res.push_back(mat[i][right]);
                }
                dir=3;
                right--;
            }
            else if(dir==3)
            {
                for(int i=right;i>=left;i--)
                {
                    res.push_back(mat[bottom][i]);
                }
                dir=4;
                bottom--;
            }
            else if(dir==4)
            {
                for(int i=bottom;i>=top;i--)
                {
                    res.push_back(mat[i][left]);
                }
                dir=1;
                left++;
            }
        }
        return res;
    }
};