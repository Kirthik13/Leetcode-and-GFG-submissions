class Solution {
public:
    vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
    
    bool isvalid(vector<vector<int>>& v,int r,int c,int m,int n,int val,vector<vector<int>>&vis)
    {
      
        return r<0 or c<0 or c>=n or r>=m or v[r][c]>val or vis[r][c]==1;
    }
    bool cancross(vector<vector<int>>& v,int r,int c,int &canalt,int &canpac,int m,int n)
    {
        if(r<0) canpac=1;
        if(c<0) canpac=1;
        if(r>=m) canalt=1;
        if(c>=n) canalt=1;
        
        if(canalt and canpac) return 1;
        return 0;
    }
    void dfs(vector<vector<int>>& v,int r,int c,int &canalt,int &canpac,int m,int n,vector<vector<int>>&vis) 
    {
        vis[r][c]=1;
        if(canpac and canalt) return;
        for(auto &i:dir)
        {
            int newr=i[0]+r;
            int newc=i[1]+c;
            
            if(canpac and canalt) return;
            
            if(cancross(v,newr,newc,canalt,canpac,m,n))
            {
                return;
            }
            if(!isvalid(v,newr,newc,m,n,v[r][c],vis))
            {
                dfs(v,newr,newc,canalt,canpac,m,n,vis);
            }
            
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& v) {
         vector<vector<int>>totans;
        
        int m=v.size(),n=v[0].size();
                vector<vector<int>>vis(m,vector<int>(n));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int canalt=0,canpac=0;
                vis.assign(m,vector<int>(n,0));
                dfs(v,i,j,canalt,canpac,m,n,vis);
                if(canalt and canpac)
                {
                    totans.push_back({i,j});
                }
            }
        }
        return totans;
    }
};