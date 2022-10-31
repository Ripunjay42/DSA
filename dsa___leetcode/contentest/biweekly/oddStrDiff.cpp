class Solution {
public:
    string oddString(vector<string>& words) 
    {
        int n=words.size();
        int s=words[0].size();
        map<vector<int>, int> m;
        for(int i=0;i<n;i++)
        {   
            vector<int> v1;
            for(int j=1;j<s;j++)
            {
                v1.push_back(words[i][j]-words[i][j-1]);
            }
            m[v1]++;
            
        }
        vector<int> v2;
        for(auto i:m)
        {
            if(i.second==1)
                v2=i.first;
        }
        for(int i=0;i<n;i++)
            {
                vector<int> v3;
                for(int j=1;j<s;j++)
                {
                    v3.push_back(words[i][j]-words[i][j-1]);
                }
        if(v3==v2)
        {
            return (words[i]);
        }        
         }
        return words[0];
    }
};