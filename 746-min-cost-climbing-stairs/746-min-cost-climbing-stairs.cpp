class Solution {
public:
    unordered_map<int,int>dp;
    int fn(int idx,vector<int>&v)
    {
        if(idx>=v.size())
        {
            return 0;
        }
        if(dp.find(idx)!=dp.end()) return dp[idx];
        return dp[idx]=min(v[idx]+fn(idx+1,v),v[idx]+fn(idx+2,v));
    }
    int minCostClimbingStairs(vector<int>& v) {
        return min(fn(0,v),fn(1,v));
    }
};