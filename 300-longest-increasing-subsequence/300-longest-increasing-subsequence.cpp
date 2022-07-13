class Solution {
public:
    int fn(vector<int>&v,int idx,int n,int previdx, vector<vector<int>>&dp)
    {
        if(idx>=n) return 0;
        
        if(dp[idx][previdx]!=-1) return dp[idx][previdx];
        
        int call1{},call2{};
        if((idx==1 and v[idx]>=v[previdx]) or (idx>1 and v[idx]>v[previdx]))
        {
            call1=1+fn(v,idx+1,n,idx,dp);
        }
        call2=fn(v,idx+1,n,previdx,dp);

        return dp[idx][previdx]=max({call1,call2});
       
    }
    int lengthOfLIS(vector<int>& v) {
        v.insert(v.begin(),INT_MIN);
                int n=v.size();
        vector<int>dp(n+1,0);
        // vector<int>curr(n+1,0);

        
        for(int idx=n-1;idx>=1;idx--)
        {
            int temp=dp[idx];

            for(int previdx=n-1;previdx>=0;previdx--)
            {
                 int call1{},call2{};
                if((idx==1 and v[idx]>=v[previdx]) or (idx>1 and v[idx]>v[previdx]))
                {
                    call1=1+temp;
                }
                call2=dp[previdx];

                dp[previdx]=max({call1,call2});
            }
            // dp=curr;
        }
        
        return dp[0];
        // return fn(v,1,n,0,dp);
    }
};