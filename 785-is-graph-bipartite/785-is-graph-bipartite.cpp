class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int>&vis,int prev,int node)
    {
        vis[node]=prev;
        for(auto &i:graph[node])
        {
            if(!vis[i])
            {
                if(!dfs(graph,vis,1-prev,i)) return 0;
            }
            else{
                if(prev==vis[i]) return 0;
            }
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        if(n==1) return 1;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(!dfs(graph,vis,0,i)) return 0;
            }
        }
        return 1;
        // vector<vector<int>>adj[n];
        
    }
};