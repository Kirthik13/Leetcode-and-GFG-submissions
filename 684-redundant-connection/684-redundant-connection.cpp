class Solution {
public:
    bool dfs( vector<vector<int>>&v,int node, vector<int>&vis,int par)
    {
        vis[node]=1;
        for(auto &it:v[node])
        {
            if(!vis[it])
            {
                dfs(v,it,vis,node);
            }
            else if(par!=it)
            {
                return 1;
            }
        }
        return 0;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
       vector<vector<int>>v(n+1); 
        vector<int>vis(n+1,0);
        for(auto &i:edges)
        {
            fill(begin(vis), end(vis), false); 
            
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
            
            if(dfs(v,i[0],vis,-1)) return i;
            
        }
        
     
        return {};
    }
};