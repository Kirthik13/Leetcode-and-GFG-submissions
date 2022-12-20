class Solution {
public:
    void dfs(vector<vector<int>>& v,int node, vector<int>&vis)
    {
        vis[node]=1;
        for(auto &i:v[node])
        {
            if(!vis[i])
            {
                dfs(v,i,vis);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& v) {
        int n=v.size();
        vector<int>vis(n);
        dfs(v,0,vis);
        int sum=accumulate(begin(vis),end(vis),0);
        return sum==n;
    }
};