#define ll long long 
class Solution {
public:
    long long mostPoints(vector<vector<int>>& v) {
          int n=v.size();
    vector<long long int>dp(n+1,-1);
   ll int m=v[0].size();
    // memset(dp,-1,sizeof(dp));
    for(int i=n-1;i>=0;i--)
    {
        ll take=v[i][0];
        if(i+v[i][1]+1 <n)
        {

          take+=dp[i+v[i][1]+1];
        }
    ll nottake=dp[i+1];
    dp[i]=max(take,nottake);
    }
        return dp[0];
    }
};