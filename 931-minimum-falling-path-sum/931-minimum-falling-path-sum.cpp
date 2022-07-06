class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& v) {
        int m=v.size(),n=v[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int r=m-1;r>=0;r--)
        {
            // vector<int>curr(n,0);
            for(int c=n-1;c>=0;c--)
            {
                if(r==m-1 )
                {
                    // curr[c]=v[r][c];
                     dp[r][c]=v[r][c];

                    continue;
                }
                
                // int dwn=(r+1<m)?dp[c]:INT_MAX;
                // int dwnlft=(r+1<m and c-1>=0)?dp[c-1]:INT_MAX;
                // int dwnrgt=(r+1<m and c+1<n)?dp[c+1]:INT_MAX;
                
                int dwn=(r+1<m)?dp[r+1][c]:INT_MAX;
                int dwnlft=(r+1<m and c-1>=0)?dp[r+1][c-1]:INT_MAX;
                int dwnrgt=(r+1<m and c+1<n)?dp[r+1][c+1]:INT_MAX;
                
                dp[r][c]=min({dwn,dwnlft,dwnrgt})+v[r][c];

                
                
            }
            // dp=curr;
        }
        
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,dp[0][i]);
        }
        return ans;
    }
};