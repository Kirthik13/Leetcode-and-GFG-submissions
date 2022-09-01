class Solution {
public:
    long dp[ 2501];
    int fn(vector<int>&v,int idx,int n)
    {
        if(idx<0) return 0;
        
        if(dp[idx]!=-1)    return dp[idx];
        
        int ans=1;
        for(int prev=0;prev<idx;prev++)
        {
            if(v[prev]<v[idx]){
                ans=max(ans,1+fn(v,prev,n));
            }
        }
        return dp[idx]=ans;
    }
    int lengthOfLIS(vector<int>& v) {
        memset(dp,-1,sizeof(dp));
        int n=v.size();
        int g=fn(v,0,n);
        
        int ans=1;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,fn(v,i,n));
        }
        return ans;
    }
};