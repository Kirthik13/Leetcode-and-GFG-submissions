class Solution {
public:
    vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
    
    bool isvalid(vector<vector<int>>&v,int x,int y,int m,int n,int max_diff,int prev,vector<vector<int>>&vis)
    {
        return x<0 or y<0 or x>=m or y>=n or abs(v[x][y]-prev)>max_diff or vis[x][y]==1;
    }
    bool dfs(vector<vector<int>>&v,int x,int y,int m,int n,int max_diff,vector<vector<int>>&vis)
    {
        if(x==m-1 and y==n-1)
        {
            return true;
        }
        
        vis[x][y]=1;
        for(auto &i:dir)
        {
            int newx=x+i[0];
            int newy=y+i[1];
            int prev=v[x][y];
            if(!isvalid(v,newx,newy,m,n,max_diff,prev,vis))
            {
                if(dfs(v,newx,newy,m,n,max_diff,vis)) return 1;
            }
            
        }
        return 0;
    }
    bool cando(vector<vector<int>>&v,int max_diff,int m,int n)
    {
        int dfsmin=INT_MAX;
        vector<vector<int>>vis(m,vector<int>(n,0));
        return dfs(v,0,0,m,n,max_diff,vis);
    }
    int minimumEffortPath(vector<vector<int>>& v) {
        
        int l=0,r=1e6,m=v.size(),n=v[0].size();
        
        while(l<r)
        {
            int mid=l+((r-l)/2);
            
            if(cando(v,mid,m,n))
            {
                r=mid;
                
            }
            else{
                l=mid+1;
            }
        }
        return l;
        
    }
};