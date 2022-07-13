class Solution {
public:

    
 int fn(vector<int>&v,int idx,int n,int previdx, vector<vector<int>>&dp)
    {
        if(idx>=n) return 0;
        
        if(dp[idx][previdx]!=-1) return dp[idx][previdx];
        
        int call1{};
     
        if(idx==previdx)
        {
            call1=1+fn(v,idx+1,n,idx,dp);
            call1=max(call1,fn(v,idx+1,n,idx+1,dp));
        }
     else{
        if( v[idx]>v[previdx])
        {
            call1=1+fn(v,idx+1,n,idx,dp);
        }
        call1=max(call1,fn(v,idx+1,n,previdx,dp));
     }

        return dp[idx][previdx]=call1;

       
    }
    
    int lengthOfLIS(vector<int>& v) {
        // v.insert(v.begin(),INT_MIN);
                int n=v.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
//         vector<int>dp(n+1,0);
//         // vector<int>curr(n+1,0);

        
        for(int idx=n-1;idx>=0;idx--)
        {

            for(int previdx=n-1;previdx>=0;previdx--)
            {
                        int call1{};
     
                        if(idx==previdx)
                        {
                            call1=1+dp[idx+1][idx];
                            call1=max(call1,dp[idx+1][idx+1]);
                        }
                        else
                        {
                            if( v[idx]>v[previdx])
                            {
                                call1=1+dp[idx+1][idx];
                            }
                            call1=max(call1,dp[idx+1][previdx]);
                       }

                      dp[idx][previdx]=call1;
            }
            // dp=curr;
        }
        
        return dp[0][0];
        // return fn(v,0,n,0,dp);
    }
};