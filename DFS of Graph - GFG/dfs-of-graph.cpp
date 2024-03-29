// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    // void dfs(vector<int>&tot,vector<int> adj[],int node,vector<int>&vis)
    // {
    //     vis[node]=1;
    //     tot.emplace_back(node);
    //     for(auto i:adj[node])
    //     {
    //         if(!vis[i]){
    //         dfs(tot,adj,i,vis);
    //         }
    //     }
        
    // }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>tot;
        vector<int>vis(V,0);
        stack<int>st;
        st.push(0);
        vis[0]=1;
            tot.emplace_back(0);
        while(!st.empty())
        {
            int node=st.top();
           
            int f=0;
            if(!vis[node]){
            tot.emplace_back(node);
            }
            vis[node]=1;
            
            for(auto &i:adj[node])
            {
                if(!vis[i])
                {
                    st.push(i);
                    // vis[i]=1;
                    f=1;
                    break;
                }
            }
            if(!f) {
                st.pop();
            }
        }
        return tot;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends