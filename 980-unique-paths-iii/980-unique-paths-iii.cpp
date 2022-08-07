class Solution {
public:
    vector<vector<int>>dir={{-1,0},{0,1},{0,-1},{1,0}};
    bool isvalid(vector<vector<int>>& grid,int x,int y,int m,int n, vector<vector<int>>&vis)
    {
        return x<0 or y<0 or x>=m or y>=n or grid[x][y]==-1 or vis[x][y]==1;
    }
    
    int dfs(vector<vector<int>>& grid,int r,int c,int m,int n, vector<vector<int>>&vis,vector<pair<int,int>>&emp)
    {
        if(grid[r][c]==2)
        {
           for(auto &i:emp)
           {
               if(vis[i.first][i.second]==0) return 0;
           }
            return 1;
        }
        
        vis[r][c]=1;
        int cnt{};
       for(auto &i:dir)
        {
                int nx=r+i[0];
                int ny=c+i[1];
                
                if(!isvalid(grid,nx,ny,m,n,vis))
                {
                    cnt+=dfs(grid,nx,ny,m,n,vis,emp);
                }
                
        }
        vis[r][c]=0;
        return cnt;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int str=-1,stc=-1;
        vector<pair<int,int>>emp;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    str=i;
                    stc=j;
                    // break;
                }
                if(grid[i][j]==0)
                {
                    emp.push_back({i,j});
                }
            }
        }
//         queue<pair<int,int>>q;
//         q.push({0,0});
//         int cnt{};
        
//         while(!q.empty())
//         {
//             auto x=q.front().first;
//             auto y=q.front().second;
            
//             q.pop();
            
//             if(grid[x][y]==2)
//             {
//                 cnt++;
//                 // break;
//                 continue;
//             }
            
//             for(auto &i:dir)
//             {
//                 int nx=x+i[0];
//                 int ny=y+i[1];
                
//                 if(!isvalid(grid,nx,ny,m,n))
//                 {
//                     q.push({nx,ny});
//                 }
                
//             }
            
            
            
//         }
        
        vector<vector<int>>vis(m,vector<int>(n,0));
       return dfs(grid,str,stc,m,n,vis,emp);
        // return cnt;
    }
};