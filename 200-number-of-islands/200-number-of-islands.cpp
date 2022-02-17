class Solution {
public:
    vector<int>dx={0,1,0,-1};
    vector<int>dy={1,0,-1,0};

    void fn(vector<vector<char>>& v,int i,int j,  vector<vector<int>>&vis)
    {
        if(i==v.size()) return;
        if(j==v[0].size()) return;
        if(i<0 or j<0) return;
        vis[i][j]=1;
        if(v[i][j]=='1')
        {
            for(int s=0;s<4;s++)
            {
                int x=i+dx[s],y=j+dy[s];
                
                if((x>=0 and x<=v.size()-1) and  (y>=0 and y<=v[0].size()-1))
                {
                    if(!vis[x][y] and v[x][y]=='1' )
                    {
                        fn(v,x,y,vis);
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& v) {
        // fn(v,0,0);
        int ans{};
        vector<vector<int>>vis(v.size(),vector<int>(v[0].size(),0));
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[0].size();j++)
            {
                if(v[i][j]=='1' and !vis[i][j])
                {
                    fn(v,i,j,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};