class Solution {
public:
    map<pair<int,int>,int>dp;
    vector<pair<int,int>>dir={{1,0},{0,1}};
    int dfs(int row,int col,vector<vector<int>>& v)
    {
        if(row==v.size()-1 and col==v[0].size()-1 )
        {
            return 1;
            
        }
        if(dp.find({row,col})!=dp.end()) return dp[{row,col}];
        int ans=0;
        for(auto &i:dir)
        {
            int dx=row+i.first,dy=col+i.second;
            
            if(dx>=0 and dx<v.size() and dy>=0 and dy<v[0].size() and v[dx][dy]==0)
            {
                ans+=dfs(dx,dy,v);
            }
        }
        return dp[{row,col}]=ans;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        if(v[0][0] == 1 or v[v.size()-1][v[0].size()-1]==1) return 0;
        return dfs(0,0,v);
    }
};