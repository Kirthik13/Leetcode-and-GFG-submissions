class Solution {
public:
    vector<vector<int>>totans;
    
    void fn(vector<vector<int>>& v,int node,vector<int>&vis,vector<int>&temp,int n)
    {
        if(node==n-1)
        {
            temp.push_back(node);
            totans.push_back(temp);
            temp.pop_back();
            
            return;
        }
        
        
        vis[node]=1;
        temp.push_back(node);
        for(auto &it:v[node])
        {
            if(!vis[it])
            {
                
                fn(v,it,vis,temp,n);
            }
        }
        if(temp.size()>0) temp.pop_back();
        vis[node]=0;
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& v) {
        int n=v.size();
        
        vector<int>vis(n,0);
        vector<int>temp;
        
        fn(v,0,vis,temp,n);
        
        return totans;
    }
};