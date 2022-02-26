class Solution {
public:
    int shortestPathLength(vector<vector<int>>& v) {
        if(v[0].size()==0) return 0;
        if(v.size()==1) return 1;
        
        int finalstate=(1<<v.size())-1;
        
        queue<pair<int,int>>q;
        
        for(int i=0;i<v.size();i++)
        {
            q.push({i,1<<i});
        }
        // unordered_map<pair<int,int>,int>m;
         map<pair<int ,int> ,int > m;
        int ans{};
        while(!q.empty())
        {
            int n=q.size();
            
            ans++;
            for(int i=0;i<n;i++)
            {
                int curnode=q.front().first;
                int curbitstate=q.front().second;
                q.pop();
                
                for(auto &j:v[curnode])
                {
                    int newvisnode=curbitstate|(1<<j);
                    if(m.find({j,newvisnode})!=m.end()) continue;
                    m[{j,newvisnode}]=1;
                    if(newvisnode==finalstate) return ans;
                    q.push({j,newvisnode});
                }
            }
        }
        return -1;
    }
};