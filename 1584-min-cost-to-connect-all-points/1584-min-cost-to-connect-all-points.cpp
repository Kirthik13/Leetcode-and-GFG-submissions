class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& graph) {
        vector<vector<pair<int,int>>>dist(graph.size());
        for(int i=0;i<graph.size();i++)
        {
            for(int j=i+1;j<graph.size();j++)
            {
                int len=abs(abs(graph[i][0]-graph[j][0])+abs(graph[i][1]-graph[j][1]));
                dist[i].push_back({j,len});
                dist[j].push_back({i,len});
            }
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<int>vis(graph.size(),0);
        pq.push({0,{0,0}});
        int cost{},nos{};
        while(nos<vis.size())
        {
                int curr_node=pq.top().second.second;
                // int g=accumulate(begin(vis),end(vis),0);
            // if(g==vis.size()) break;
                if(vis[curr_node]==0)
                {
                    cost+=pq.top().first;
                    // cout<<pq.top().first<<" "<<pq.top().second.first<<" " <<pq.top().second.second<<endl;
                    vis[curr_node]=1;
                    pq.pop();
                    nos++;
                    for(auto &i:dist[curr_node])
                    {
                        pq.push({i.second,{curr_node,i.first}});
                        // cout<<curr_node<<" "<<i.first<<" "<<i.second<<endl;
                    }
                    
                
                    
                    
                }
            else{
                pq.pop();
            }
        }
        return cost;
    }
};