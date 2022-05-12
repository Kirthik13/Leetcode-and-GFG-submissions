class Solution {
public:
    unordered_map<int,int>dp;
    // int fn(int idx,vector<int>&v)
    // {
    //     if(idx>=v.size())
    //     {
    //         return 0;
    //     }
    //     if(dp.find(idx)!=dp.end()) return dp[idx];
    //     return dp[idx]=max(v[idx]+fn(idx+2,v),fn(idx+1,v));
    // }
    int rob(vector<int>& v) {
        // return fn(0,v);
        int n=v.size();
        dp[n]=0;
        dp[n+1]=0;
        for(int idx=n-1;idx>=0;idx--)
        {
            
            dp[idx]=max(v[idx]+dp[idx+2],dp[idx+1]);
        }
        return dp[0];
    }
};