class Solution {
public:
       vector<int>dx={0,1,0,-1};
    vector<int>dy={1,0,-1,0};
    int maxAreaOfIsland(vector<vector<int>>& v) {
           int ans{};
        // vector<vector<int>>vis(v.size(),vector<int>(v[0].size(),0));
        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[0].size();j++)
            {
                if(v[i][j]==1)
                {
                    // fn(v,i,j,vis);
                    
                    int curr=0;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    v[i][j]=0;
                    while(!q.empty())
                    {
                        curr++;
                        int i1=q.front().first;
                        int j1=q.front().second;
                        q.pop();

                        for(int s=0;s<4;s++)
                        {
                            int x=i1+dx[s],y=j1+dy[s];

                            if((x>=0 and x<=v.size()-1) and  (y>=0 and y<=v[0].size()-1) and v[x][y]==1)
                            {
                                
                                    q.push({x,y});
                                    v[x][y]=0;

                                
                            }
                        }
                    }
                    ans=max(ans,curr);
                }
            }
        }
        return ans;
    }
};