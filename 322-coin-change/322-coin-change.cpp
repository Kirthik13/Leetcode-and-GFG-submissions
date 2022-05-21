class Solution {
public:
    // int ans=INT_MIN;
    // map<pair<int,int>,int>dp;
    
    int dp[10001][13];
   int fn(vector<int>& v, int amt,int n)
   {
       if(n==-1 or amt==0)
       {
           if(amt==0) return 0;
           return INT_MAX;
       }
       if(dp[amt][n]!=-1) return dp[amt][n];
       if(v[n]>amt)
       {
            return dp[amt][n]=fn(v,amt,n-1);

       }
       int l=fn(v,amt-v[n],n);
       if(l==INT_MAX)
       {
            return dp[amt][n]=fn(v,amt,n-1);
       }
       
       return dp[amt][n]=min(1+l,fn(v,amt,n-1));
   }
    int coinChange(vector<int>& v, int amt) {
        memset(dp,-1,sizeof(dp));
        int g=fn(v,amt,v.size()-1);
        return g==INT_MAX?-1:g;
    }
};