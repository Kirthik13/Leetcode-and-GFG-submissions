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
    //     return dp[idx]=min(v[idx]+fn(idx+1,v),v[idx]+fn(idx+2,v));
    // }
    int minCostClimbingStairs(vector<int>& v) {
        int n=v.size();
        
        dp[n]=0;
        dp[n-1]=v[n-1];
        dp[n-2]=v[n-2];
        for(int idx=n-1;idx>=0;idx--)
        {
            int f=INT_MAX,s=INT_MAX;
            if(idx+1<=n)
            {
                f=v[idx]+dp[idx+1];
            
                 if(idx+2<=n)
                {
                    s=v[idx]+dp[idx+2];
                }
                 dp[idx]=min(f,s);
            }
           
            
        }
        
        return min(dp[0],dp[1]);
    }
};