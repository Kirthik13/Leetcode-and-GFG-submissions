class Solution {
public:
    bool check(int &x,int &y,int &m,int &n,vector<vector<int>>& vis,vector<vector<int>>& v)
    {
        return x<0 or y<0 or x>=m or y>=n or vis[x][y]==1 or v[x][y]==1;
    }
    int maxDistance(vector<vector<int>>& v) {
        vector<pair<int,int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
        queue<pair<pair<int,int>,int>>q;
        int m=v.size(),n=v[0].size();
        vector<vector<int>>vis(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]==1) q.push({{i,j},0});
            }
        }
        int ans=-1;
        while(!q.empty())
        {
            auto curr=q.front();
            q.pop();
            int x=curr.first.first;
            int y=curr.first.second;
            int dis=curr.second;
            if(v[x][y]==0) ans=max(ans,dis);
            for(auto &i:dir)
            {
                int newx=x+i.first;
                int newy=y+i.second;
                
                if(!check(newx,newy,m,n,vis,v))
                {
                    q.push({{newx,newy},dis+1});
                    vis[newx][newy]=1;
                }
                
            }
            
        }
        return ans;
    }
};