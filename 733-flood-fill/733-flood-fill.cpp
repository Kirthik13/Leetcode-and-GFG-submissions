class Solution {
public:
    vector<pair<int,int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
   
    void dfs(vector<vector<int>>& v, int sr, int sc, int val,int color,int m,int n)
    {
        if(sr<0 or sr>=m or sc<0 or sc>=n or v[sr][sc]==color or v[sr][sc]!=val) return ;
       
        
        v[sr][sc]=color;
        
        dfs(v,sr-1,sc,val,color,m,n);
        dfs(v,sr+1,sc,val,color,m,n);
        dfs(v,sr,sc+1,val,color,m,n);
        dfs(v,sr,sc-1,val,color,m,n);
        

    }
    vector<vector<int>> floodFill(vector<vector<int>>& v, int sr, int sc, int color) {
        int m=v.size(),n=v[0].size();
        dfs(v,sr,sc,v[sr][sc],color,m,n);
        return v;
    }
};