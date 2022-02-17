class Solution {
public:
    void fn(vector<int>&v,int &k,vector<int> &sam,set<vector<int>>&tot,int idx,int sum)
    {
        
        if(sum>k)
            {
                return;
            }
        if(sum==k)
            {
                tot.insert(sam);
            }
        if(idx>=v.size())
        {
            // if(sum==k)
            // {
            //     tot.emplace_back(sam);
            // }
            return;
        }
        
        sam.emplace_back(v[idx]);
        fn(v,k,sam,tot,idx,sum+v[idx]);
        sam.pop_back();
        fn(v,k,sam,tot,idx+1,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& v, int k) {
        set<vector<int>> tot;
        vector<int>sam;
        fn(v,k,sam,tot,0,0);
        vector<vector<int>>ans;
        for(auto &i:tot)
        {
            ans.emplace_back(i);
        }
        return ans;
    }
};