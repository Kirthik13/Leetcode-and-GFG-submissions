class Solution {
public:
    bool fn2(vector<int>&v,int sum,int idx,int k,vector<int>&dp)
    {
        if(sum==k) return 1;
        if(sum<k) return 0;
        if(idx>=v.size()) return 0;
        if(dp[k]!=-1) return dp[k];
        for(int i=idx;i<v.size();i++)
        {
            if(k+v[i]<=sum)
            {
                if(fn2(v,sum,i+1,k+v[i],dp))
                {
                    return dp[k+v[i]]=1;
                }
                
            }
        }
        return dp[k]=0;
    }
    bool fn(vector<int>&v,int sum)
    {
        vector<int>dp(sum+1,-1);
       return fn2(v,sum,0,0,dp);
    }
    bool canPartition(vector<int>& v) {
        int sum=accumulate(begin(v),end(v),0);
        if(sum&1) return 0;
        return fn(v,sum/2);
    }
};