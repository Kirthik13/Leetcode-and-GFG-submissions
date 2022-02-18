// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
   	bool dfs(int node, vector<int>&vis,vector<int>&dvis,vector<int> adj[])
	{
	    vis[node]=1;
	    dvis[node]=1;
	    for(auto it:adj[node])
	    {
	        if(vis[it]==-1)
	        {
	            if(dfs(it,vis,dvis,adj))
	            {
	                return 1;
	            }
	        }
	        else if(vis[it]==1 and dvis[it]==1){
	            return 1;
	        }
	    }
	    dvis[node]=-1;
	    return 0;
	}
	bool isCyclic(int n, vector<int> adj[]) 
	{
	    vector<int>vis(n,-1);
	    vector<int>dvis(n,-1);
	    for(int i=0;i<n;i++){
	        if(vis[i]==-1)
	        {
	            if(dfs(i,vis,dvis,adj))
	            {
	                return 1;
	            }
	        }
	    }
	    return 0;
	   	// code here
	}
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends