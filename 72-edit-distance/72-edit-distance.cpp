class Solution {
public:
    int fn(string &s,string &t,int idx1,int idx2,int m,int n,  vector<vector<int>>&dp)
    {
        if(idx1>=m and idx2>=n) return 0;
        
        if(idx1>=m )
        {
            return n-idx2;
        }

        if(idx2>=n )
        {
            return m-idx1;
        }
        
        if(dp[idx1][idx2]!=-1)   return dp[idx1][idx2];
        
        if(s[idx1]==t[idx2])
        {
            return fn(s,t,idx1+1,idx2+1,m,n,dp);
        }
        
        int call1=1+fn(s,t,idx1+1,idx2,m,n,dp);//in
        int call2=1+fn(s,t,idx1+1,idx2+1,m,n,dp);//re
        int call3=1+fn(s,t,idx1,idx2+1,m,n,dp);//del
        
        return dp[idx1][idx2]=min({call1,call2,call3});
        
        
        
    }
        
    int minDistance(string s, string t) {
        int m=s.size(),n=t.size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fn(s,t,0,0,m,n,dp);
    }
};