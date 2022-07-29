class Solution {
public:
    
 
    
     void dfs(vector<vector<int>>&v,int x,int y,int n,int max_dpt,vector<vector<int>>&vis)
    {
        
            if(!vis[x][y] and v[x][y]<=max_dpt)
            {
                vis[x][y]=1;
                
                if(x+1<n) dfs(v,x+1,y,n,max_dpt,vis);
                if(x-1>=0) dfs(v,x-1,y,n,max_dpt,vis);
                if(y-1>=0) dfs(v,x,y-1,n,max_dpt,vis);
                if(y+1<n) dfs(v,x,y+1,n,max_dpt,vis);
                
                
                
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