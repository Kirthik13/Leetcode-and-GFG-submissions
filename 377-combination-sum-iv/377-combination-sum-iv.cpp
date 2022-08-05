class Solution {
public:
    int fn(vector<int>&v,int sum,int target,vector<int>&dp)
    {
        if(sum==target) return 1;
        
        if(dp[sum]!=-1) return dp[sum];
        
        int c{};
        for(auto &i:v)
        {
            if(i+sum<=target)
            {
                c+=fn(v,i+sum,target,dp);
            }
        }
        return dp[sum]=c;
    }
    int combinationSum4(vector<int>& v, int target) {
        vector<int>dp(target+1,0);
        
        dp[target]=1;
        
        for(int sum=target-1;sum>=0;sum--)
        {
            long long int c{};
            for(auto &i:v)
            {
                if(i+sum<=target)
                {
                    c+=dp[i+sum];
                }
            }
            dp[sum]=c;
        }
        
        return dp[0];
        // return fn(v,0,target,dp);
    }
};