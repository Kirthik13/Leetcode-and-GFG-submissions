class Solution {
public:
    bool bfs(vector<vector<int>>& graph, vector<int>&vis,int node)
    {
        // vis[node]=prev;
        // for(auto &i:graph[node])
        // {
        //     if(!vis[i])
        //     {
        //         if(!dfs(graph,vis,1-prev,i)) return 0;
        //     }
        //     else{
        //         if(prev==vis[i]) return 0;
        //     }
        // }
        // return 1;
        
        queue<int>q;
        q.push(node);
        vis[node]=0;
        while(!q.empty())
        {
            int el=q.front();
            q.pop();
            for(auto &i:graph[el])
            {
                if(!vis[i])
                {
                    vis[i]=1-vis[el];
                    q.push(i);
                }
                else{
                    if(vis[el]==vis[i]) return 0;
                }
            }
        }
        return  1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        if(n==1) return 1;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(!bfs(graph,vis,i)) return 0;
            }
        }
        return 1;
        // vector<vector<int>>adj[n];
        
    }
};