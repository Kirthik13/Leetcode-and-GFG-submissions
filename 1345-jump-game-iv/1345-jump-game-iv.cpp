class Solution {
public:
    int minJumps(vector<int>& v) {
        int n=v.size();
        map<int,vector<int>>m;
        for(int i=0;i<v.size();i++)
        {
            m[v[i]].push_back(i);
        }
        
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<int>vis(n,0);
        int ans=INT_MAX;
        
        while(!q.empty())
        {
            auto idx=q.front().first;
            auto dis=q.front().second;
            vis[idx]=1;
            q.pop();
            
            if(idx==n-1)
            {
                ans=min(dis,ans);
               
                continue;
            }
            if(idx+1<n and vis[idx+1]==0){
                q.push({idx+1,dis+1});
            }
            
            if(idx-1>=0 and vis[idx-1]==0)
            {
                            q.push({idx-1,dis+1});

            }
            
             for(auto j:m[v[idx]])
                {
                    if(!vis[j] and j!=idx)
                    {
                        q.push({j,dis+1});
                    }
                }
            
            m.erase(v[idx]);
            
           
            
            
        }
        
        return ans;
        
        
    }
};