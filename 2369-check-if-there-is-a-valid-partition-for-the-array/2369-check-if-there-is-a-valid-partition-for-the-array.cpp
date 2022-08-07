class Solution {
public:
    bool fn(vector<int>&v,int idx,int n,vector<int>&dp)
    {
        if(idx>=n) return 1;
        
        if(dp[idx]!=-1) return dp[idx];
        
        int res{};
        if(idx+2<n)
        {
            if(v[idx]==v[idx+1] and v[idx]==v[idx+2])  res|=(fn(v,idx+3,n,dp));
            if(v[idx]+1==v[idx+1] and v[idx]+2==v[idx+2] and v[idx+1]+1==v[idx+2])  res|=(fn(v,idx+3,n,dp));
            
                
        }
        if(idx+1<n)
        {
            if(v[idx]==v[idx+1] )  res|=(fn(v,idx+2,n,dp));

        }
        
        return dp[idx]=res;
    }
        
    bool validPartition(vector<int>& v) {
        int n=v.size();
        vector<int>dp(n,-1);
       return fn(v,0,n,dp);
    }
};