class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vec;
        unordered_set<int> ust;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int lo = 0;
        int hi = nums2.size() - 1;
        for(int i=0;i<nums1.size();i++) {
            int lo = 0;
            int hi = nums2.size() - 1;
            while(lo <= hi) {
                int mid = lo + (hi-lo)/2;
                if(nums1[i] == nums2[mid]) {
                    ust.insert(nums1[i]);
                    break;
                }
                else if(nums1[i] < nums2[mid]) {
                    hi = mid - 1;
                }
                else {
                    lo = mid + 1;
                }
            }
        }
        for(auto it : ust) {
            vec.push_back(it);
        } 
        return vec;
        
    }
};