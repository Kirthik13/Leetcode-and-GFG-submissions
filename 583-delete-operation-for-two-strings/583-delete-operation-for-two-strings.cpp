class Solution {
public:
    // map<pair<int,int>,int>dp;
    int dp[501][501];
    int fn(string s1,string s2,int i,int j,int m,int n)
    {
       if(i==m and j==n ) return 0;
       if(i==m) return n-j;
       if(j==n) return m-i;
        
        if(dp[i][j]!=-1) return dp[i][j];
       if(s1[i]==s2[j])
       {
           return dp[i][j]=fn(s1,s2,i+1,j+1,m,n);
       }
        
        
        return dp[i][j]=1+min(fn(s1,s2,i+1,j,m,n),fn(s1,s2,i,j+1,m,n));
        
    }
    int minDistance(string s1, string s2) {
        
        int m=s1.size(),n=s2.size();
        memset(dp,-1,sizeof(dp));
        return fn(s1,s2,0,0,m,n);
    }
};