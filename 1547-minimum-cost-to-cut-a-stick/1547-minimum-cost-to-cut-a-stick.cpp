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
        vector<vector<int>>dp(c+1,vector<int>(c+1,-1));
        return f(1,c,v,dp);
    }
};