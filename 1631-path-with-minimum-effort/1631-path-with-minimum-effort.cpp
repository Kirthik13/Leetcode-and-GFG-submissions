class Solution {
private:
      vector<vector<int>>vis;
    vector<int>dirx={-1,0,1,0};
    vector<int>diry={0,1,0,-1};

    int m,n;
public:
  
    bool isvalid(int x,int y)
    {
        return x>=0 and x<m and y>=0 and y<n;
        
    }
    bool dfs( vector<vector<int>>&v,int x,int y,int mid)
    {
        vis[x][y]=1;

        if(x==m-1 and y==n-1) return 1;

        for(int i=0;i<4;i++)
        {
            int dx=x+dirx[i],dy=y+diry[i];
            if(isvalid(dx,dy) and vis[dx][dy]==0 and abs(v[x][y]-v[dx][dy])<=mid)
            {
                if(dfs(v,dx,dy,mid)) return 1;
                    
            }
        }
        return 0;
    }
    bool isok(vector<vector<int>>&v,int mid)
    {
        vis.assign(m,vector<int>(n,0));
        // for(auto i:vis)
        // {
        //     for(auto j:i)
        //     {
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        return dfs(v,0,0,mid);
    }
    int minimumEffortPath(vector<vector<int>>& v) {
        int l=0,r=(1e6);
        int ans=INT_MAX;
        m=v.size();
        n=v[0].size();
        while(l<=r)
        {
            int mid=l+((r-l)/2);
            if(isok(v,mid))
            {
                r=mid-1;
                ans=min(ans,mid);
            }
            else{
                l=mid+1;
            }
        }
        return ans==INT_MAX?0:ans;
        // return l;
    }
};