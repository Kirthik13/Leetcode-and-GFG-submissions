class Solution {
public:
    int dp[100][100][21];
    const int mx = 1e7+1;
    int fn(vector<int>& v, vector<vector<int>>& cost, int idx, int grp,int prevcolor, int target,int n)
    {
        if(idx>=v.size())
        {
            return (target==grp)?0:mx;
        }
        
        if(dp[idx][grp][prevcolor]!=-1) return dp[idx][grp][prevcolor];
        
        int mincost=mx;
        
        if(v[idx])
        {
            if(prevcolor!=v[idx])
            {
                mincost=fn(v,cost,idx+1,grp+1,v[idx],target,n);
            }
            else  mincost=fn(v,cost,idx+1,grp,prevcolor,target,n);
        }
        else{
            for(int j=0;j<n;j++)
            {
                
                int tmp;  //store the current cost
                int new_color=j+1;
                if((new_color)!=prevcolor) tmp = cost[idx][j] +  fn(v,cost,idx+1,grp+1,new_color,target,n);
                
                else tmp = cost[idx][j] + fn(v,cost,idx+1,grp,new_color,target,n);
                mincost=min(mincost,tmp);
                
            }
        }
        return dp[idx][grp][prevcolor]=mincost;
    }
    int minCost(vector<int>& v, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans= fn(v,cost,0,0,0,target,n);
        if(ans==mx) return -1;
        else return ans;
        
    }
};