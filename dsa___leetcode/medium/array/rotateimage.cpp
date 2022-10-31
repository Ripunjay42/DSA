class Solution {
public:
    void rotate(vector<vector<int>>& mat) 
    {
        int n=mat.size();
        int top=0, right=n-1;
        vector<vector<int>> res;
        while(top<right)
        {
            for(int i=0;i<right-top;i++)
            {
                swap(mat[top][top+i], mat[top+i][right]);
                swap(mat[top][top+i], mat[right][right-i]);
                swap(mat[top][top+i], mat[right-i][top]);
            }
            top++;
            right--;
        }
    }
};