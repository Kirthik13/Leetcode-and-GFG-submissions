class Solution {
public:
    int fn(int r,int c,int m,int n,vector<vector<int>>&dp)
    {
        if(r>=m or c>=n)
        {
            return 0;
        }
        if(r==m-1 and c==n-1)
        {
            return 1;
        }
        if(dp[r][c]!=-1) return dp[r][c];
        
        return dp[r][c]=fn(r,c+1,m,n,dp)+fn(r+1,c,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return fn(0,0,m,n,dp);
    }
};