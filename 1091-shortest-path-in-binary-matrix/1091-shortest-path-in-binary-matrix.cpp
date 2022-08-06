class Solution {
public:
    vector<vector<int>>dir={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    
    bool isvalid(vector<vector<int>>& grid,int x,int y,int m,int n)
    {
        return x<0 or y<0 or x>=m or y>=n or grid[x][y]>0;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int ans=INT_MAX,m=grid.size(),n=grid[0].size();
        if(grid[0][0]==1 or grid[m-1][n-1]==1) return -1;
        
         // queue<pair<int, int>> queue;
        // queue.push(make_pair(0,0));
        // vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
        grid[0][0] = 1;
      
        
        
        queue<pair<int,int>>q;
        q.push({0,0});
        
        
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            
            auto x=node.first;
            auto y=node.second;
            auto wt=grid[x][y];
            
            if(x==m-1 and y==n-1)
            {
                        return wt;
            }
            for(auto &it:dir)
            {
                int newx=it[0]+x;
                int newy=it[1]+y;
                
                if(!isvalid(grid,newx,newy,m,n))
                {
                   
                    q.push({newx,newy});
                    grid[newx][newy]=1+grid[x][y];
                }
                
            }
            
        }
        
        return -1;
        
            
    }
};