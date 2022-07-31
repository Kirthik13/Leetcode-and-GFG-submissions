class Solution {
public:
    int ans=INT_MIN;
    void fn(vector<int>&v,int node, vector<int>&vis, vector<int>&dvis)
    {
        
            if(node==-1) return;
            
            if(vis[node])
            {
                int count=-1;
                for(int i=0;i<dvis.size();i++)
                {
                    if(node==dvis[i])
                    {
                        count=i;
                        break;
                    }
                }
                if(count!=-1)
                {
                    int n=dvis.size();
                    ans=max(ans,n-count);
                }
                return;
            }
            
            vis[node]=1;
            dvis.push_back(node);
            fn(v,v[node],vis,dvis);
           
        
    }
    int longestCycle(vector<int>& v) {
        int n=v.size();
        vector<int>vis(n);
        for(int i=0;i<n;i++)
        {
            vector<int>dvis;
            
            if(!vis[i])
            {
            fn(v,i,vis,dvis);
            }
            
        }
        
        return ans==INT_MIN?-1:ans;
        
    }
};