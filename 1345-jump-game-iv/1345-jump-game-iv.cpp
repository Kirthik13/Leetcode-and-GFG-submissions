class Solution {
public:
    int minJumps(vector<int>& v) {
        int n=v.size();
        unordered_map<int,vector<int>>m;
        for(int i=0;i<v.size();i++)
        {
            m[v[i]].push_back(i);
        }
        
        queue<pair<int,int>>q;

        q.push({0,0});
        
        // vector<int>vis(n);
        int ans=INT_MAX;
        
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int elidx=it.first;
            // vis[elidx]=1;
            int steps=it.second;
            
            if(elidx==n-1)
            {
                ans=min(ans,steps);
                
            }
            else
            {
                if(elidx+1<n and m.find(v[elidx+1])!=m.end())
                {
                q.push({elidx+1,steps+1});
                }
                if(elidx-1>=0 and m.find(v[elidx-1])!=m.end()){
                q.push({elidx-1,steps+1});
                }
                for(auto j:m[v[elidx]])
                {
                    if( j!=elidx)
                    {
                        q.push({j,steps+1});
                    }
                }
            }
            m.erase(v[elidx]);
        }
        return ans;
    }
};