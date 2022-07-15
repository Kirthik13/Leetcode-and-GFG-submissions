class Solution {
public:
    vector<pair<int,int>>dir={{-1,0},{0,1},{1,0},{0,-1}};
    int dfs(vector<vector<int>>& v,int i,int j,int m,int n)
    {
          v[i][j] = 0;
        int ans=0;
        for(auto &d:dir)
        {
            int new_x=i+d.first;
            int new_y=j+d.second;
            
            if(new_x>=0 and new_x<m and new_y>=0 and new_y<n and v[new_x][new_y]==1)
            {            
                // cout<<"newx: "<<new_x<<" newy : "<<new_y<<endl;
                ans+=dfs(v,new_x,new_y,m,n);
            }

        }
        // cout<<"ans : "<<ans<<endl;
        return 1+ans;
        
    }
    int maxAreaOfIsland(vector<vector<int>>& v) {
        int m=v.size(),n=v[0].size();
        int call1{},ans{};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if( v[i][j]==1)
                {
                    int call1=dfs(v,i,j,m,n);
                    // cout<<"cal 1 : "<<call1<<endl;
                    ans=max(call1,ans);
                }
            }
                
        }
        return ans;
    }
};