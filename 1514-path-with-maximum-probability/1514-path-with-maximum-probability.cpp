class Solution {
public:
 
    double maxProbability(int n, vector<vector<int>>& ed, vector<double>& sp, int st, int end) {
         vector<vector<pair<int,double>>>v(n);
        for(auto i=0;i<ed.size();i++)
        {
            v[ed[i][0]].push_back({ed[i][1],sp[i]});
            v[ed[i][1]].push_back({ed[i][0],sp[i]});

            
        }
 
        vector<double>dis(n);
        queue<int> q;
        dis[st] = 1;
        q.push(st);
        while(!q.empty()){
            int p = q.front(); q.pop();
            for(auto x : v[p]){
                int i = x.first;
                double j = x.second;
                if(dis[p]*j > dis[i]){
                    dis[i] = dis[p]*j;
                    q.push(i);
                }
            }
        }
        return dis[end];
        // return dfs(v,sp,vis,st,end,n);
    }
};