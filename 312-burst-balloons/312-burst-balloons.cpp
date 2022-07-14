class Solution {
public:
    int fn(int i,int j,vector<int>& v,vector<vector<int>>dp)
{
    if(i>j) return 0;
   
    if(dp[i][j]!=-1) return dp[i][j];
   
    int ans{};
    for(int idx=i;idx<=j;idx++)
    {
        int gain=v[i-1]*v[idx]*v[j+1];
        int call1=gain+fn(i,idx-1,v,dp)+fn(idx+1,j,v,dp);
        ans=max(ans,call1);
    }
    
    return dp[i][j]=ans;
}
    int maxCoins(vector<int>& v) {
         int n=v.size();
    v.insert(v.begin(),1);
    v.push_back(1);
    vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        
        for(int i=n;i>=1;i--)
        {
            for(int j=i;j<=n;j++)
            {
                  int ans{};
                for(int idx=i;idx<=j;idx++)
                {
                    int gain=v[i-1]*v[idx]*v[j+1];
                    int call1=gain+dp[i][idx-1]+dp[idx+1][j];
                    ans=max(ans,call1);
                }

                dp[i][j]=ans;
            }
        }
        
        return dp[1][n];
    // return fn(1,n,v,dp);
    }
};