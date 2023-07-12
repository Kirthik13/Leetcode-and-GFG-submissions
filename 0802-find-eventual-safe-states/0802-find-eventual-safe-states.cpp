class Solution {
public:
    set<int>st;
    int dfs(int node,vector<vector<int>>& v,vector<int>&vis) 
    {
        int cnt{};
        vis[node]=1;
        for(auto &i:v[node])
        {
            
                if(v[i].size()==0 or st.find(i)!=st.end())
                {
                    cnt++;
                }
                else if(!vis[i])
                {
                    int g=dfs(i,v,vis);
                    if(g==123) cnt++;
                }
                
        }
        if(cnt==v[node].size())
        {
            st.insert(node);
            return 123;
        }
        return 0;
        
        
        
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& v) {
        
        int n=v.size();
        vector<int>vis(n);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
               dfs(i,v,vis);
            }
        }
        vector<int>totans(begin(st),end(st));
        
        return totans;

    }
};