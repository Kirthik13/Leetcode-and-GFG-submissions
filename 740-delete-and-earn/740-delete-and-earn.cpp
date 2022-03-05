class Solution {
public:
    int deleteAndEarn(vector<int>& v) {
        int freq[10001]={0},dp[10001]={0};
        for(auto &i:v)
        {
            freq[i]++;
        }
        dp[0]=0;
        dp[1]=freq[1];
        for(int i=2;i<10001;i++)
        {
            dp[i]=max(dp[i-1],freq[i]*i+dp[i-2]);
        }
        return dp[10000];
        
    
    }
};