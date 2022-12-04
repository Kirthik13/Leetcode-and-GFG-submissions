class Solution {
public:
    
    void dfs(int node,int dest, vector<vector<pair<int,int>>>&v,vector<int>&vis,int &ans)
    {
        
        vis[node]=1;
        if(node==dest) return ;
        
        
        
        for(auto &i:v[node])
        {
        int dist=i.second;
                ans=min(dist,ans);            
            if(!vis[i.first])
            {
               

                dfs(i.first,dest,v,vis,ans);
            }
            
        }
        // vis[node]=1;
        // for(auto p:v[node]){
        //     int nextnode=p.first;
        //     int wt=p.second;
        //     ans=min(ans, wt);
        //     if(!vis[nextnode]){
        //         dfs(nextnode,dest,v,vis,ans);
        //     }
        // }
        
    }
    int minScore(int n, vector<vector<int>>& g) {
        
        
        vector<vector<pair<int,int>>>v(n+1);
        
        for(auto &i:g)
        {
            v[i[0]].push_back({i[1],i[2]});
            v[i[1]].push_back({i[0],i[2]});
            
        }
    
        int ans=INT_MAX;
        vector<int>vis(n+1);
        
      
            
        dfs(1,n,v,vis,ans);
        return ans;
    }
};