class Solution {
public:
    int dp[201][201];
    int fn(vector<vector<int>>& v,int r,int c,int m,int n) 
    {
        if(r>=m or c>=n) return INT_MAX;
        
        if(r==m-1 and c==n-1)
        {
            return v[r][c];
        }
        
        if(dp[r][c]!=-1) return dp[r][c];
        
        int ans=INT_MAX;
        if(r+1<m)
        {
            ans=min(v[r][c]+fn(v,r+1,c,m,n),ans);
        }
        if(c+1<n)
        {    
            ans=min(v[r][c]+fn(v,r,c+1,m,n),ans);
        }
        return dp[r][c]=ans;
            
    }
    
    int minPathSum(vector<vector<int>>& v) {
        int m=v.size(),n=v[0].size(),ans=INT_MAX;
        memset(dp,-1,sizeof(dp));
        
        return fn(v,0,0,m,n);
    }
};