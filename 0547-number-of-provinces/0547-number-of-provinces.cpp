class Solution {
public:
    void dfs(int node,vector<vector<int>>& v,  vector<int> &vis)
    {
        vis[node]=1;
        queue<int>q;
        q.push(node);
        
        while(!q.empty())
        {
            int node1=q.front();
            q.pop();
            for(auto &i:v[node1])
            {
                if(!vis[i])
                {
                    vis[i]=1;
                    q.push(i);
                    // dfs(i,v,vis);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>v(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                
                if(graph[i][j]) v[i].push_back(j);
            }
        }
        int c{};
        vector<int>vis(n);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,v,vis);
                c++;
            }
        }
        return c;
    }
};