class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) 
    {
        unordered_map<string, long long> sum_views, popular;
    vector<vector<string>> res;
    long long max_views = 0;
    for (int i = 0; i < ids.size(); ++i) {
        max_views = max(max_views, sum_views[creators[i]] += views[i]);
        auto it = popular.find(creators[i]);
        if (it == end(popular))
            popular[creators[i]] = i;
        else if (views[i] >= views[it->second]) {
            if (views[i] == views[it->second])
               it->second = ids[i] < ids[it->second] ? i : it->second;
            else
               it->second = i;
        }
    }
    for (auto &[creator, sum] : sum_views)
        if (sum == max_views)
            res.push_back({creator, ids[popular[creator]]});
    return res;
    }
};