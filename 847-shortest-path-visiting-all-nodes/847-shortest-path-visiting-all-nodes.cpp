class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size();
        int fstate=(1<<n)-1;
        
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++)
        {
            int st=(1<<i);
            q.push({i,st});
        }
        
        map<pair<int,int>,int>m;
        int ans{};
        while(!q.empty())
        {
            
            int siz=q.size();
            ans++;
            for(int i=0;i<siz;i++)
            {
                auto node=q.front().first;
                auto currstate=q.front().second;
                q.pop();
                
                for(auto &it:graph[node])
                {
                    auto childnode=it;
                     int newstate=currstate|(1<<childnode);
                    if(newstate==fstate) return ans;
                    if(m.find({childnode,newstate})!=m.end()) continue;
                    
                    m[{childnode,newstate}]=1;
                    q.push({childnode,newstate});
                    
                    
                }
            }
            
            
        }
        return 0;
    }
};