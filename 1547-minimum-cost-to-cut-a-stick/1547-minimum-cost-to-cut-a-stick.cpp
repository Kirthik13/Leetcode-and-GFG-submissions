class Solution {
public:
    int f(int i,int j,vector<int>&v,vector<vector<int>>&dp)
    {
        if(i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=INT_MAX;
        for(int idx=i;idx<=j;idx++)
        {
            int cost=(v[j+1]-v[i-1])+f(i,idx-1,v,dp)+f(idx+1,j,v,dp);
            
            ans=min(cost,ans);
        }
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& v) {
        int c=v.size();
        v.push_back(n);
        v.insert(v.begin(),0);
        sort(begin(v),end(v));
        vector<vector<int>>dp(c+2,vector<int>(c+2,0));
        
        for(int i=c;i>=1;i--)
        {
            for(int j=1;j<=c;j++)
            {
                if(i>j) continue;
                 
                int ans=INT_MAX;
                for(int idx=i;idx<=j;idx++)
                {
                    int cost=(v[j+1]-v[i-1])+dp[i][idx-1]+dp[idx+1][j];

                    ans=min(cost,ans);
                }
                dp[i][j]=ans;
            }
        }
        
        return dp[1][c];
        // return f(1,c,v,dp);
    }
};