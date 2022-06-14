class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& v) {
        
        int n=v.size();
            
        queue<pair<int,vector<int>>>q;
        vector<vector<int>>tot;
        
        q.push({0,{0}});
        
        while(!q.empty())
        {
            auto p=q.front();
            int node=p.first;
            vector<int>path=p.second;
            q.pop();
            
            if(node==n-1)
            {
                tot.push_back(path);
                continue;
            }
                
            for(auto &it:v[node])
            {
                path.push_back(it);
                q.push({it,path});
                path.pop_back();
            }
        }
        return tot;
        
    }
};