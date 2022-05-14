class Solution {
public:
  
    int networkDelayTime(vector<vector<int>>& v, int n, int k) {
        
        vector<vector<pair<int,int>>>adj(n+1);
        
        for(auto &i:v)
        {
            int src=i[0],des=i[1],wt=i[2];
            adj[src].push_back({des,wt});
        }
        
        vector<int>vis(n+1,0);
        vector<int>dist(n+1,INT_MAX);
    
        vis[k]=0;
        dist[k]=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        
        while(!pq.empty())
        {
            int node=pq.top().second;
            pq.pop();
            if(vis[node]) continue;
            vis[node]=1;
            
            for(auto it:adj[node])
            {
                int des=it.first,wt=it.second;
                
                if(dist[des]>dist[node]+wt)
                {
                    dist[des]=dist[node]+wt;
                    pq.push({dist[des],des});
                }
            }
        }
        int ans=*max_element(dist.begin()+1,dist.end());
        return ans==INT_MAX?-1:ans;
        
     
    }
};