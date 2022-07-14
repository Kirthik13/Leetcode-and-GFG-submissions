class Solution {
public:
    int countSquares(vector<vector<int>>& v) {
        int m=v.size(),n=v[0].size();
          vector<vector<int>>dp(m,vector<int>(n,0));
        for(int r=0;r<m;r++)
        {
            dp[r][0]=v[r][0];
        }
         for(int c=0;c<n;c++)
        {
            dp[0][c]=v[0][c];
        }
        int ans{};
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(v[i][j]==0)
                {
                    dp[i][j]=0;
                }
                else {
                    dp[i][j]=1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
                }
            }
        }
    for(auto &i:dp)
    {
        for(auto &j:i) ans+=j;
    }
        return ans;
    }
};