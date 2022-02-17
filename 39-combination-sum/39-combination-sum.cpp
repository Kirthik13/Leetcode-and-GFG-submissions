class Solution {
public:
    void fn(vector<int>&v,int &k,vector<int> &sam,vector<vector<int>>&tot,int idx,int sum)
    {
        
        if(sum>k)
            {
                return;
            }
        if(sum==k)
            {
                tot.emplace_back(sam);
            return;
            }
      
        for(int j=idx;j<v.size();j++){
            if(sum+v[j]<=k){
        sam.emplace_back(v[j]);
        fn(v,k,sam,tot,j,sum+v[j]);
        sam.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& v, int k) {
        vector<vector<int>> tot;
        vector<int>sam;
        fn(v,k,sam,tot,0,0);
        return tot;
    }
};