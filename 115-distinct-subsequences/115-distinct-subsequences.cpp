class Solution {
public:
    const int mod=1000000007;

    int numDistinct(string s, string t) {
        int m=s.size(); int n=t.size();
        vector<int>dp(n+1,0);
//     vector<int>curr(n+1,0);
    
//     dp[n]=curr[n]=1;
    dp[n]=1;
  
    for(int idx1=m-1;idx1>=0;idx1--)
    {
        int prev=dp[n];
        for(int idx2=n-1;idx2>=0;idx2--)
        {
            int curr=dp[idx2];
            int call1{},call2{};
            if(s[idx1]==t[idx2])
            {
                call1+=prev;//prev
            }
       
                call2+=dp[idx2];
                
            
            dp[idx2]=(call1+call2)%mod;
            prev=curr;
        }
//         dp=curr;
    }
//    
    
    return dp[0];
    }
};