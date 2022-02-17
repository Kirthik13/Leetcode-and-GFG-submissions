class Solution {
public:
    bool fn2(vector<int>&v,int sum,int idx,int k,vector<vector<int>>&dp)
    {
        if(sum==k) return 1;
        if(sum<k) return 0;
        if(idx>=v.size()) return 0;
        if(dp[idx][k]!=-1) return dp[idx][k];
        for(int i=idx;i<v.size();i++)
        {
            if(k+v[i]<=sum)
            {
                if(fn2(v,sum,i+1,k+v[i],dp))
                {
                    return dp[i][k+v[i]]=1;
                }
                
            }
        }
        return dp[idx][k]=0;
    }
    bool fn(vector<int>&v,int sum)
    {
     vector<vector<int>>dp(v.size(),vector<int>(sum+1,0));
        
        for(int i=0;i<v.size();i++)
        {
            dp[i][0]=1;
        }
        for(int ind = 1; ind<v.size(); ind++)
        {
            for(int target= 1; target<=sum; target++){

                bool notTaken = dp[ind-1][target];

                bool taken = false;
                    if(v[ind]<=target)
                        taken = dp[ind-1][target-v[ind]];

                dp[ind][target]= notTaken||taken;
            }
     }
    
    return dp[v.size()-1][sum];
        
        // return fn2(v,sum,0,0,dp);
    }
    bool canPartition(vector<int>& v) {
        int sum=accumulate(begin(v),end(v),0);
        if(sum&1) return 0;
        return fn(v,sum/2);
    }
};