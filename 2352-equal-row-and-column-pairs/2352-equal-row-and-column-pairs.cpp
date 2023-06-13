class Solution {
public:
    int equalPairs(vector<vector<int>>& v) {
        map<vector<int>,int>m;
        int ans{};
        for(auto &i:v)
        {
            m[i]++;
            
        }
        
        // for(auto &i:m)
        // {
        //     for(auto &j:i.first) cout<<j<<" ";
        //     cout<<endl;
        // }
        
        for(int i=0;i<v[0].size();i++)
        {
            vector<int>v2;
            for(int j=0;j<v.size();j++)
            {
                v2.push_back(v[j][i]);
            }
            
            if(m.find(v2)!=m.end())
            {
                auto it=m.find(v2);
                ans+=it->second;
            }
        }
        
        return ans;
    }
};