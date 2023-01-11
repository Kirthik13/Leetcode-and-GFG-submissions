class Solution {
public:
    int dfs(vector<vector<int>>& v,int node,int cost,  vector<int>&vis,vector<bool>& ha) 
    {
        int childcost{};
        vis[node]=1;
        for(auto &i:v[node])
        {
            if(!vis[i])   
            {
                childcost+=dfs(v,i,2,vis,ha);
            }
        }
        
        if(childcost==0 and !ha[node]) return 0;
        
        return childcost+cost;
    }
    int minTime(int n, vector<vector<int>>& ed, vector<bool>& ha) {
        vector<vector<int>>v(n);
        vector<int>vis(n);
        for(auto &i:ed)
        {
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
            
        }
        
        return dfs(v,0,0,vis,ha);
    }
};