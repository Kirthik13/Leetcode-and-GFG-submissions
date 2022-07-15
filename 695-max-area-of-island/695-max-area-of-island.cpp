class Solution {
public:
    int dfs(vector<vector<int>>& v,int i,int j,int m,int n)
    {
        if(i<0 or j<0 or i>=m or j>=n or  v[i][j]==0) return 0;
          v[i][j] = 0;
  
        return 1+dfs(v,i-1,j,m,n)+dfs(v,i+1,j,m,n)+dfs(v,i,j-1,m,n)+dfs(v,i,j+1,m,n);
        
    }
    int maxAreaOfIsland(vector<vector<int>>& v) {
        int m=v.size(),n=v[0].size();
        int call1{},ans{};
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]==1)
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