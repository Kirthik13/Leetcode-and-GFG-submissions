class Solution {
public:
    int fn(string &s1,string &s2,int n,int m,int i1,int i2,vector<vector<int>>&dp)
    {
        if(n==i1 or m==i2) return 0;
        if(dp[i1][i2]!=-1)  return dp[i1][i2];
        if(s1[i1]==s2[i2])
        {
            return dp[i1][i2]=1+fn(s1,s2,n,m,i1+1,i2+1,dp);
        }
        
           return dp[i1][i2]=max(fn(s1,s2,n,m,i1+1,i2,dp),fn(s1,s2,n,m,i1,i2+1,dp));
        
    }
    int longestCommonSubsequence(string s1, string s2) {
        if(s1.size()<s2.size()) swap(s1,s2);
        int n=s1.size(),m=s2.size();
        vector<vector<int>>dp(1001,vector<int>(1001,-1));
       return fn(s1,s2,n,m,0,0,dp);
    }
};