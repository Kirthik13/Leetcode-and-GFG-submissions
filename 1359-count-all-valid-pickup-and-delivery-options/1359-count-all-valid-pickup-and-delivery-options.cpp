#define ll long long int
#define mod 1000000007
class Solution {
public:
    int countOrders(int n) {
        ll dp[501]={0};
        dp[1]=1*1LL;
        dp[2]=6*1LL;
        
        for(int i=3;i<=n;i++)
        {
            ll oddno=2*i-1;
            ll per=(oddno*(oddno+1))/2;
            
            dp[i]=(dp[i-1]*per)%mod;
        }
        return dp[n];
        
    }
};