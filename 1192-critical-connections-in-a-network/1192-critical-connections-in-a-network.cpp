class Solution {
public:
    
    void dfs(vector<vector<int>>&v,int node, vector<int>&vis, vector<int>&dis, vector<int>&low,int &time,int par,vector<vector<int>>&totans)
    {
        vis[node]=1;
        dis[node]=low[node]=time++;
        
        for(auto &it:v[node])
        {
            if(it==par) continue;
            if(!vis[it])
            {
                dfs(v,it,vis,dis,low,time,node,totans);
                low[node]=min(low[node],low[it]);
                
                if(dis[node]<low[it])
                {
                    totans.push_back({node,it});
                }

            }
            else{
                low[node]=min(low[node],low[it]);
            }
              
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& graph) {
        vector<vector<int>>v(n);
        for(auto &i:graph)
        {
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
            
        }
        
        vector<int>dis(n,INT_MAX);
        vector<int>vis(n);
        vector<int>low(n,INT_MAX);
          vector<vector<int>>totans;
        
        int time=1;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(v,i,vis,dis,low,time,-1,totans);
            }
        }
        
        return totans;
        
    }
};