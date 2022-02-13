class Solution {
public:
    set<vector<int>>tot;
    void fn(vector<int> &v,int idx,vector<int>sam)
    {
        if(idx>=v.size())
        {
            tot.insert(sam);
            return;
        }
        fn(v,idx+1,sam);
        sam.push_back(v[idx]);
        fn(v,idx+1,sam);
        sam.pop_back();
    }
    vector<vector<int>>subsets(vector<int>& v) {
        vector<int>sam;
        fn(v,0,sam);
        vector<vector<int>>ans;
        
        for(auto i:tot)
        {
            ans.push_back(i);
        }
        return ans;
    }
};