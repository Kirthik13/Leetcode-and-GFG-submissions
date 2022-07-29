class Solution {
public:
    
  vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
    bool isvalid(vector<vector<int>>&v,int x,int y,int n,int max_dpt,vector<vector<int>>&vis)
    {
        return x<0 or y<0 or x>=n or y>=n or v[x][y]>max_dpt or vis[x][y]==1;
    }
    
     void dfs(vector<vector<int>>&v,int x,int y,int n,int max_dpt,vector<vector<int>>&vis)
    {
        
            if(!vis[x][y] and v[x][y]<=max_dpt)
            {
                vis[x][y]=1;
                for(auto &i:dir)
                {
                    int newx=x+i[0];
                    int newy=y+i[1];

                    if(!isvalid(v,newx,newy,n,max_dpt,vis))
                    {
                        dfs(v,newx,newy,n,max_dpt,vis) ;
                    }

                }
                // if(x+1<n) dfs(v,x+1,y,n,max_dpt,vis);
                // if(x-1>=0) dfs(v,x-1,y,n,max_dpt,vis);
                // if(y-1>=0) dfs(v,x,y-1,n,max_dpt,vis);
                // if(y+1<n) dfs(v,x,y+1,n,max_dpt,vis);
                
                
                
            }
         
    
    }
  
    int swimInWater(vector<vector<int>>& v) {
        int l=v[0][0],r=2500,n=v.size();
        
        for(auto &i:v)
        {
            r=max(*max_element(begin(i),end(i)),r);
        }
        
        
        while(l<r)
        {
            int mid=l+((r-l)/2);
            vector<vector<int>>vis(n,vector<int>(n,0));
            dfs(v,0,0,n,mid,vis);
            if(vis[n-1][n-1]==1)
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