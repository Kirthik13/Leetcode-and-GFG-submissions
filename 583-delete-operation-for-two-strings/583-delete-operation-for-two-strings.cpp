class Solution {
public:
    int fn(string s, string t,int idx1,int idx2,int m,int n, vector<vector<int>>&dp)
    {
        if(idx1>=m and idx2>=n) return 0;
        if(idx1>=m) return n-idx2;
        if(idx2>=n) return m-idx1;

        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        
        if(s[idx1]==t[idx2])
        {
            return fn(s,t,idx1+1,idx2+1,m,n,dp);
        }
        int call1=INT_MAX,call2=INT_MAX;
        call1=1+fn(s,t,idx1+1,idx2,m,n,dp);
        call2=1+fn(s,t,idx1,idx2+1,m,n,dp);
        
        return dp[idx1][idx2]=min(call1,call2);

    }
    int minDistance(string s, string t) {
          int m=s.size(),n=t.size();
            vector<vector<int>>dp(m+1,vector<int>(n+1,1e5));
            
                    dp[m][n]=0;

            for(int idx2=n-1;idx2>=0;idx2--)
            {
                dp[m][idx2]=n-idx2;
            }
             for(int idx1=m-1;idx1>=0;idx1--)
            {
                dp[idx1][n]=m-idx1;
            }
            for(int idx1=m-1;idx1>=0;idx1--)
            {
                for(int idx2=n-1;idx2>=0;idx2--)
                {
                      
                    if(s[idx1]==t[idx2])
                    {
                        dp[idx1][idx2]=dp[idx1+1][idx2+1];
                        continue;
                    }
                    int call1=INT_MAX,call2=INT_MAX;
                    call1=1+dp[idx1+1][idx2];
                    call2=1+dp[idx1][idx2+1];

                    dp[idx1][idx2]=min(call1,call2);
                }

            }
            // return fn(s,t,0,0,m,n,dp);
        return dp[0][0];
            
            
    }
};