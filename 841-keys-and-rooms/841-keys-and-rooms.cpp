class Solution {
public:
    void dfs(vector<vector<int>>&v,int node,vector<int>&vis)
    {
        vis[node]=1;
        for(auto &it:v[node])
        {
            if(!vis[it])
            {
                dfs(v,it,vis);
            }
        }
            
        
    }
    bool canVisitAllRooms(vector<vector<int>>& v) {
        int n=v.size();
        vector<int>vis(n,0);
        dfs(v,0,vis);
        int sum=accumulate(begin(vis),end(vis),0);
        if(sum==n) return 1;
        return 0;
        
        
    }
};