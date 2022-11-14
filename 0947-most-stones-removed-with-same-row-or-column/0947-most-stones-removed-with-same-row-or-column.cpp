class Solution {
public:
    void dfs(vector<vector<int>>& v,vector<int>&vis,int &idx,int n)
    {
        vis[idx]=1;
        for(int i=0;i<n;i++)
        {
            if(!vis[i] and (v[idx][0]==v[i][0] or v[idx][1]==v[i][1] ))
            {
            
                dfs(v,vis,i,n);
            }
        }
        
    }
    int removeStones(vector<vector<int>>& v) {
        int cnt{};
        int n=v.size();
        vector<int>vis(n);
        for(int i=0;i<n;i++)
        {
            if(vis[i]) continue;
            
            dfs(v,vis,i,n);
            cnt++;
        }
        
        return n-cnt;
    }
};