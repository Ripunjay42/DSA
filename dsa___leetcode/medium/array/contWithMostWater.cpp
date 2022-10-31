class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int water=0;
        int j=height.size()-1;
        int i=0;
        while(i<j)
        {
            int h=min(height[i], height[j]);
            int area=(j-i)*h;
            water=max(water, area);
            while(height[i]<=h && i<j)
                i++;
            while(height[j]<=h && i<j)
                j--;
        }
        return water;
    }
};