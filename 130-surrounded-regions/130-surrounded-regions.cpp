class Solution {
public:
    vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
    bool isvalid(vector<vector<char>>& v,int r,int c,int m,int n)
    {
        return r<0 or c<0 or r>=m or c>=n or v[r][c]=='X' or v[r][c]=='z';
    }
    void dfs(vector<vector<char>>& v,int r,int c,int m,int n)
    {
        v[r][c]='z';
        
        for(auto &i:dir)
        {
            int x=r+i[0];
            int y=c+i[1];
            
            if(!isvalid(v,x,y,m,n))
            {
                dfs(v,x,y,m,n);
            }
            
        }
    }
    void solve(vector<vector<char>>& v) {
        int m=v.size(),n=v[0].size();
        
        for(int i=0;i<n;i++)
        {
            if(v[0][i]=='O')
            {
                dfs(v,0,i,m,n);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(v[m-1][i]=='O')
            {
                dfs(v,m-1,i,m,n);
            }
        }
         for(int i=0;i<m;i++)
        {
            if(v[i][0]=='O')
            {
                 dfs(v,i,0,m,n);
            }
        }
         for(int i=0;i<m;i++)
        {
            if(v[i][n-1]=='O')
            {
                 dfs(v,i,n-1,m,n);
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]=='z') v[i][j]='O';
                else if(v[i][j]=='O') v[i][j]='X';
            }
        }
        
    }
};