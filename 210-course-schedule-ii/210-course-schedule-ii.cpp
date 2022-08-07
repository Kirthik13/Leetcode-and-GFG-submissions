class Solution {
public:
    void dfs( vector<vector<int>>&v,int node,vector<int>&vis,stack<int>&st)
    {
        vis[node]=1;
        for(auto &it:v[node])
        {
            if(!vis[it])
            {
                dfs(v,it,vis,st);
            }
        }
        
        st.push(node);
        
    }
    bool cydfs(vector<vector<int>>&v,int node,vector<int>&vis,vector<int>&dvis)
    {
        vis[node]=1;
        dvis[node]=1;
        for(auto &it:v[node])
        {
            if(!vis[it] and !dvis[it])
            {
                if(cydfs(v,it,vis,dvis)) return 1;
            }
            else{
                if(dvis[it]==vis[it]){
                return 1;
                }
            }
        }
        dvis[node]=0;
        return 0;
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>>v(n);
        
        for(auto &i:pre)
        {
            v[i[1]].push_back(i[0]);
        
        }
        
        vector<int>vis1(n);
        vector<int>dvis(n);
        for(int i=0;i<n;i++)
        {
            if(cydfs(v,i,vis1,dvis)) return {};
        }
        
        stack<int>st;
        vector<int>vis(n);
        vector<int>ans;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(v,i,vis,st);
            }
        }
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
        
    }
};