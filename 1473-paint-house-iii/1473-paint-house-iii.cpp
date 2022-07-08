class Solution {
public:
    int dp[100][100][21];
    const int mx = 1e7+1;
    int fn(vector<int>& v, vector<vector<int>>& cost, int idx, int grp,int prevcolor, int target)
    {
        if(idx>=v.size())
        {
            return (target==grp)?0:mx;
        }
        // if(idx > v.size()) return mx;
        
        if(dp[idx][grp][prevcolor]!=-1) return dp[idx][grp][prevcolor];
        
        int mincost=mx;
        
        if(v[idx])
        {
            if(prevcolor!=v[idx])
            {
                mincost=fn(v,cost,idx+1,grp+1,v[idx],target);
            }
            else  mincost=fn(v,cost,idx+1,grp,v[idx],target);
        }
        else{
            for(int j=0;j<cost[0].size();j++)
            {
                
                int tmp;  //store the current cost
                
                if((j+1)!=prevcolor) tmp = cost[idx][j] +  fn(v,cost,idx+1,grp+1,j+1,target);
                
                else tmp = cost[idx][j] + fn(v,cost,idx+1,grp,j+1,target);
                mincost=min(mincost,tmp);
                
            }
        }
        return dp[idx][grp][prevcolor]=mincost;
    }
    int minCost(vector<int>& v, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans= fn(v,cost,0,0,0,target);
        if(ans==mx) return -1;
        else return ans;
        
    }
};