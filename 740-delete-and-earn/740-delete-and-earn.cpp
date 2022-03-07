class Solution {
public:
    int fn(int idx,vector<int>&freq,vector<int>&dp)
    {
        if(idx>=10001) return 0;
        // if(idx==v.size()-1) return v[idx];
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx]=max(idx*freq[idx]+fn(idx+2,freq,dp),fn(idx+1,freq,dp));
        
    }
    int deleteAndEarn(vector<int>& v) {
        vector<int>freq(10001,0);
        vector<int>dp(10001,-1);
        for(auto &i:v)
        {
            freq[i]++;
        }
//         dp[0]=0;
//         dp[1]=freq[1];
//         for(int i=2;i<10001;i++)
//         {
//             dp[i]=max(dp[i-1],freq[i]*i+dp[i-2]);
//         }
//         return dp[10000];
        return fn(0,freq,dp);
    
    }
};