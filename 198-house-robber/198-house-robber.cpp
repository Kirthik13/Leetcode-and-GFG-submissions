class Solution {
public:
    int ans=INT_MIN;
    int fn(int idx,vector<int>&v,vector<int>&dp)
    {
        if(idx>=v.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        ans=max(ans,max(v[idx]+fn(idx+2,v,dp),fn(idx+1,v,dp)));
        return dp[idx]=ans;
    }
    int rob(vector<int>& v) {
            vector<int>dp(101,-1);

        return fn(0,v,dp);
    }
};