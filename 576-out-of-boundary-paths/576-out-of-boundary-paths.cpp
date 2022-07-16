class Solution {
public:
    const int mod=1000000007;
    vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
    int fn(int r,int c,int m,int n,int k,vector<vector<vector<int>>>&dp)
    {

        if(r<0 or c<0 or r>=m or c>=n )
        {

            
            return 1;
        }
        if(k==0) return 0;
        
        if(dp[r][c][k]!=-1) return dp[r][c][k];
        
        int ans{};
        for(auto &i:dir)
        {
            int new_x=r+i.first;
            int new_y=c+i.second;
            
            ans=(ans+fn(new_x,new_y,m,n,k-1,dp))%mod;
        
        }
        return dp[r][c][k]=ans%mod;
    }
    int findPaths(int m, int n, int maxMove, int sr, int sc) {
          // vector<vector<vector<int>>>dp(maxMove+1,vector<vector<int>>(m+1,vector<int>(m+1,0)));
          int dp[maxMove+1][m][n];
        memset(dp,0,sizeof dp);
        for(int i=0;i<maxMove;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<n;k++){
                    if(i==0){
                        dp[i][j][k]+=(j-1<0 ? 1 : 0);
                        dp[i][j][k]+=(k-1<0 ? 1 : 0);
                        dp[i][j][k]+=(j+1 >= m ? 1 :0);
                        dp[i][j][k]+=(k+1>= n ? 1 : 0);
                    }
                    else{
                        long a=(j-1<0 ? 1 : dp[i-1][j-1][k]);
                        long b=(k-1<0 ? 1 : dp[i-1][j][k-1]);
                        long c=(j+1 >= m ? 1 : dp[i-1][j+1][k]);
                        long d=(k+1>= n ? 1 : dp[i-1][j][k+1]);
                        
                        dp[i][j][k] = ((a+b+c+d)*1L)%mod;
                    }
                }
            }
        }
        if(maxMove==0){
            return dp[0][sr][sc];
        }
        return dp[maxMove-1][sr][sc];
    }
};