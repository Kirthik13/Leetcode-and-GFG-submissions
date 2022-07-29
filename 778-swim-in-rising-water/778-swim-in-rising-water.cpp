class Solution {
public:
    vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
    
    bool isvalid(vector<vector<int>>&v,int x,int y,int n,int max_dpt,vector<vector<int>>&vis)
    {
        return x<0 or y<0 or x>=n or y>=n or v[x][y]>max_dpt or vis[x][y]==1;
    }
    
    bool dfs(vector<vector<int>>&v,int x,int y,int n,int max_dpt,vector<vector<int>>&vis)
    {
         if(x==n-1 and y==n-1)
        {
          
            return true;
        }
       
        vis[x][y]=1;
        for(auto &i:dir)
        {
            int newx=x+i[0];
            int newy=y+i[1];
            
            if(!isvalid(v,newx,newy,n,max_dpt,vis))
            {
                if(dfs(v,newx,newy,n,max_dpt,vis)) return 1;
            }
            
        }
        return 0;
        // vis[x][y]=0;
    }
    bool cando(vector<vector<int>>&v,int max_dpt,int n)
    {
        vector<vector<int>>vis(n+1,vector<int>(n+1,0));
        return dfs(v,0,0,n,max_dpt,vis);
        // return vis[n-1][n-1]==1;
    }
    int swimInWater(vector<vector<int>>& v) {
        int l=v[0][0],r=2500,n=v.size();
        
        // for(auto &i:v)
        // {
        //     r=max(*max_element(begin(i),end(i)),r);
        // }
        
        while(l<r)
        {
            int mid=l+((r-l)/2);
            
            if(cando(v,mid,n))
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