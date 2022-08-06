class Solution {
public:
    vector<vector<int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
    
    bool isvalid(vector<vector<int>>& grid, int r, int c,int m,int n)
    {
        return r<0 or c<0 or r>=m or c>=n ;
    }
    
    void dfs(vector<vector<int>>& grid, int r, int c,int m,int n,int clr)
    {
        int cnt{};
        grid[r][c]=-clr;
        for(auto &i:dir)
        {
            int newx=r+i[0];
            int newy=c+i[1];
            
            if(!isvalid(grid,newx,newy,m,n)  and  abs(grid[r][c])==abs(grid[newx][newy]))
            {
                cnt++;
                
                if(grid[newx][newy]==clr)
                {
                    dfs(grid,newx,newy,m,n,clr);
                }
               
            }
           
            
        }
        
        if(cnt==4)
        {
            grid[r][c]=clr;
        }
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r, int c, int color) {
    
        int m=grid.size(),n=grid[0].size();
        dfs(grid,r,c,m,n,grid[r][c]);
        
        for(auto &i:grid)
        {
            for(auto &j:i)
            {
                if(j<0)
                {
                    j=color;
                }
            }
        }
        
        return grid;
        
    }
};