class Solution {
public:
    bool dfs(vector<vector<int>>& v, int source, int dest,vector<int>&vis) 
    {
        if(source==dest) return 1;
        
        vis[source]=1;
        for(auto &i:v[source])
        {
            if(!vis[i])
            {
                if(dfs(v,i,dest,vis)) return 1;
            }
        }
        // vis[source]=0;
        return 0;
    }
    bool validPath(int n, vector<vector<int>>& g, int source, int dest) {
        vector<vector<int>>v(n);
        for(auto &i:g)
        {
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
            
        }
        
        vector<int>vis(n);
        if(dfs(v,source,dest,vis)) return 1;
        return 0;
    }
};