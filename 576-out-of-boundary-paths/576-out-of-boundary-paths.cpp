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
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(maxMove+1,-1)));
        return fn(sr,sc,m,n,maxMove,dp);
    }
};