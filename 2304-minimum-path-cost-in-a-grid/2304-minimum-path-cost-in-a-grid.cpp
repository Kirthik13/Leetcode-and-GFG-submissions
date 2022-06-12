class Solution {
public:
    int dp[51][51];
    int fn(vector<vector<int>>& v, vector<vector<int>>& cost,int i,int j)
    {
        if(i==v.size()-1)
        {
            return v[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int col=0;col<v[0].size();col++)
        {
            int pathcost=v[i][j]+cost[v[i][j]][col];
            int getcost=fn(v,cost,i+1,col);
            ans=min(ans,pathcost+getcost);
        }
        return dp[i][j]=ans;
    }
    int minPathCost(vector<vector<int>>& v, vector<vector<int>>& cost) {
        
        int retans=INT_MAX;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<v[0].size();i++)
        {
            retans=min(retans,fn(v,cost,0,i));
        }
        return retans;
        
    }
};