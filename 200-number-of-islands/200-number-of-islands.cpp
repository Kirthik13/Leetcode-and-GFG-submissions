class Solution {
public:
    vector<pair<int,int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
    
    bool isvalid(vector<vector<char>>& v,int r,int c)
    {
        return r<0 or c<0 or r>=v.size() or c>=v[0].size() or v[r][c]=='0';
    }
    void dfs(vector<vector<char>>& v,int r,int c)
    {
        v[r][c]='0';
        for(auto &i:dir)
        {
            int newr=i.first+r;
            int newc=i.second+c;
            
            if(!isvalid(v,newr,newc))
            {
                dfs(v,newr,newc);
            }
            
        }
    }
        
    int numIslands(vector<vector<char>>& v) {
        int c{},m=v.size(),n=v[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]=='1')
                {
                    dfs(v,i,j);
                    c++;
                }
            }
        }
        return c;
    }
};