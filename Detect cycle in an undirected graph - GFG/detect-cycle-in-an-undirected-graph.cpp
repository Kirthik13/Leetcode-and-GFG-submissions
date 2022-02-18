// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        vector<int>vis(n,-1);
        queue<int>st;
        for(int k=0;k<n;k++)
        {
            if(vis[k]==-1)
            {
                st.push(k);
                vis[k]=0;
                while(!st.empty())
                {
                    int node=st.front();
                    int f=0;
                    for(auto &i:adj[node])
                    {
                        if(vis[i]==-1 )
                        {
                            st.push(i);
                            vis[i]=0;
                            // f=1;
                            // break;
                        }
                        else if(vis[i]==0)
                        {
                            return 1;
                            
                        }
                    }
                    // if(!f)
                    // {
                        vis[st.front()]=1;
                        st.pop();
                    // }
                }
            }
        }
        return 0;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends