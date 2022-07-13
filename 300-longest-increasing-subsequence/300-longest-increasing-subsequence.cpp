class Solution {
public:
    int fn(vector<int>& v,int idx,int previdx,int n,  vector<vector<int>>&dp)
    {
        if(idx>=n) return 0;
        
        if(dp[idx][previdx+1]!=-1) return dp[idx][previdx+1];
        
        int call1{};
        if(previdx==-1 or v[idx]>v[previdx])
        {
            call1=fn(v,idx+1,idx,n,dp)+1;
        }
        call1=max(call1,fn(v,idx+1,previdx,n,dp));
        
        return dp[idx][previdx+1]=call1;

    }
    int lengthOfLIS(vector<int>& v) {
        int n=v.size();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        vector<int>dp(n+1,1);

//         for(int idx=n-1;idx>=0;idx--)
//         {
//             for(int previdx=idx-1;previdx>=-1;previdx--)
//             {
//                  int call1{};
//                 if(previdx==-1 or v[idx]>v[previdx])
//                 {
//                     call1=dp[idx+1]+1;
//                 }
//                 call1=max(call1,dp[previdx+1]);

//                 dp[previdx+1]=call1;
//             }
//             // dp=curr;
//         }
        vector<int>hash(n+1,0);
        for(int i=0;i<n;i++)
        {
            hash[i]=i;
        }
        
        
        int maxidx=0,maxinos=1;
        for(int idx=1;idx<n;idx++)
        {
            for(int prev=idx-1;prev>=0;prev--)
            {
                if(v[idx]>v[prev])
                {
                    if(dp[idx]<dp[prev]+1)
                    {
                        hash[idx]=prev;
                        dp[idx]=dp[prev]+1;
                    }
                }
                
                if(maxinos<dp[idx])
                {
                    maxidx=idx;
                    maxinos=dp[idx];
                }
            }
        }
        
        // return *max_element(begin(dp),end(dp));
        return maxinos;
        // return fn(v,0,-1,n,dp);
    }
};