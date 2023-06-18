class Solution {
public:
    int mod = 1e9 + 7;    
    vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
    bool isvalid(vector<vector<int>>& v,int r,int c,int m,int n)
    {
        return r<0 or r>=m or c<0 or c>=n ;
    }
    int fn(vector<vector<int>>& v,int r,int c,int m,int n,vector<vector<int>>&dp)
    {
        if(dp[r][c]>1) return dp[r][c];
        int ans=dp[r][c];
        for(auto &i:dir)
        {
            int newx=r+i[0];
            int newy=c+i[1];
            if((!isvalid(v,newx,newy,m,n)) )
            {
               if(v[newx][newy]>v[r][c])
               {
                // ans+=((fn(v,newx,newy,m,n,dp))%mod);
                ans = (ans + fn(v,newx, newy,  m,n,  dp)) % mod;                      
                                           
               }
            }
            
        }
        return dp[r][c]=ans;
    }
    
    int countPaths(vector<vector<int>>& v) {
        
        int m=v.size(),n=v[0].size(),ans{};
        vector<vector<int>>dp(m+1,vector<int>(n+1,1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                // ans=(ans+(fn(v,i,j,m,n,dp))%mod);
                ans = (ans + fn(v,i, j,  m,n,  dp)) % mod;                
                // ans+=((dfs(i,j,m,n,v,dp))%mod);
                
            }
        }
        return ans%mod;
    }
};