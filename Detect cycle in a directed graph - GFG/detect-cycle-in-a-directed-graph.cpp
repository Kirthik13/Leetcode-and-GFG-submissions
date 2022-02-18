// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int n, vector<int> adj[]) {
        // code here
        vector<int>vis(n,-1);
        stack<int>st;
        for(int k=0;k<n;k++)
        {
            if(vis[k]==-1)
            {
                st.push(k);
                vis[k]=0;
                while(!st.empty())
                {
                    int node=st.top();
                    int f=0;
                    vis[node]=0;
                    for(auto &i:adj[node])
                    {
                        if(vis[i]==-1 )
                        {
                            st.push(i);
                            f=1;
                            break;
                        }
                        else if(vis[i]==0)
                        {
                            return 1;
                            
                        }
                    }
                    if(!f)
                    {
                        vis[st.top()]=1;
                        st.pop();
                    }
                }
            }
        }
        return 0;
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