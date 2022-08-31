class Solution {
public:
    vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
    
    bool isvalid(vector<vector<int>>& v,int r,int c,int m,int n,int val,vector<vector<int>>&vis)
    {
        return r<0 or c<0 or c>=n or r>=m or v[r][c]<val or vis[r][c]==1;
    }
   
    void dfs(vector<vector<int>>& v,int r,int c,int m,int n,vector<vector<int>>&vis) 
    {
       
        vis[r][c]=1;
        for(auto &i:dir)
        {
            int newr=i[0]+r;
            int newc=i[1]+c;
            
            
           
            if(!isvalid(v,newr,newc,m,n,v[r][c],vis))
            {
                dfs(v,newr,newc,m,n,vis);
            }
            
        }
        // int m = matrix.length, n = matrix[0].length;
      // vis[r][c] = true;
      // for(auto &d: dir){
      //   int x = r + d[0];
      //   int y = c + d[1];
      //   // if(x < 0 || y < 0 || x >= m || y >= n || vis[x][y] || v[r][c] > v[x][y]){
      //     if(isvalid(v,x,y,m,n,v[r][c],vis)){
      //     continue;
      //   }
      //   dfs(v, x, y,m,n,vis);
      // }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& v) {
         vector<vector<int>>totans;
        
        int m=v.size(),n=v[0].size();
        vector<vector<int>>atl(m,vector<int>(n));
        vector<vector<int>>pac(m,vector<int>(n));
        
       for(int i = 0; i < m; i++){
        dfs(v,i,  0,m,n,pac);
        dfs(v,i, n - 1,m,n,atl);
      }   
      
      for(int i = 0; i < n; i++){
        dfs(v,0,  i,m,n,pac);
        dfs(v,m - 1, i,m,n,atl);
      }     
        
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pac[i][j] and atl[i][j])
                {
                    totans.push_back({i,j});
                }
            }
        }
        return totans;
    }
};