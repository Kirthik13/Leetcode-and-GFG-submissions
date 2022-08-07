class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& pts) {
        int n=pts.size();
        vector<vector<pair<int,int>>>v(n);
        for(int i=0;i<pts.size();i++)
        {
            for(int j=0;j<pts.size();j++)
            {
                if(i==j) continue;
                int wt=abs(pts[i][0]-pts[j][0])+abs(pts[i][1]-pts[j][1]);
                v[i].push_back({j,wt});
                v[j].push_back({i,wt});
                
            }
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        
        vector<int>dis(n,INT_MAX);
        vector<int>mst(n,false);
        vector<int>parent(n,-1);
        
        dis[0]=0;
        
        pq.push({0,0});
        
        while(!pq.empty())
        {
            auto node=pq.top().second;
            // auto wt=pq.top().first;
            mst[node]=1;
            pq.pop();
            
            for(auto &it:v[node])
            {
                if(!mst[it.first] and dis[it.first]>it.second)
                {
                    dis[it.first]=it.second;
                    parent[it.first]=node;
                    pq.push({dis[it.first],it.first});
                }
            }
            
        }
        
        int c{};
        for(int i=1;i<n;i++)
        {
            if(dis[i]!=INT_MAX)
            {
                c+=dis[i];
            }
        }
        
        return c;
        
    }
};