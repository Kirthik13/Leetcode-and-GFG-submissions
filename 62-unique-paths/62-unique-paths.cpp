class Solution {
public:
 
    int fn(int r,int c,int m,int n, vector<vector<int>>&dp)
{
    if(r==m-1 or c==n-1)
    {
        return 1;
    }
    if(r>=m or c>=n or c<0 or r<0) return 0;
    
    if(dp[r][c]!=-1) return dp[r][c];
    
    int left=fn(r+1,c,m,n,dp);
    int right=fn(r,c+1,m,n,dp);
    
    return dp[r][c]=left+right;
}
int uniquePaths(int m, int n) {
	// Write your code here.
    vector<vector<int>>dp(m,vector<int>(n,-1));
    
//     for(int i=m-1;i>=0;i--)
//     {
//         dp[i][n-1]=1;
//     }
//     for(int i=n-1;i>=0;i--)
//     {
//         dp[m-1][i]=1;
//     }
//     dp[m-1][n-1]=1;
    
//       int r;
//         for(int r=m-2; r>=0;r--)
//         {
//               for(int c=n-2;c>=0 ;c--){
//                 int left=((r+1>=m)?0:dp[r+1][c]);
//                 int right=((c+1>=n)?0:dp[r][c+1]);
//                 dp[r][c]=left+right;
//               }
    
//         }
        
    
//     return dp[0][0];
    
    return fn(0,0,m,n,dp);
}
};