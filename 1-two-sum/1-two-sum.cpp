class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
        int n=v.size();
        unordered_map<int,int>m;
        for(auto i=0;i<v.size();i++)
        {
            if(m.find(t-v[i])!=m.end())
            {
                return {m[t-v[i]],i};
            }
            m[v[i]]=i;
        }
        return {};
            
    }
};