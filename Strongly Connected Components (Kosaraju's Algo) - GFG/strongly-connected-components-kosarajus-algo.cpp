// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int n, vector<int> adj[])
    {
         vector<int>vis(n,0);
	    stack<int>st;
	    stack<int>st2;
	   
	    for(int i=0;i<n;i++)
	    {
	        if(vis[i])
	        {
	            continue;
	        }
	        
	        st.push(i);
	        
	        while(!st.empty())
	        {
	            int node=st.top();
	            int f=0;
	            vis[node]=1;
	            for(auto &j:adj[node])
	            {
	                if(!vis[j])
	                {
	                    st.push(j);
	                    f=1;
	                    break;
	                }
	            }
	            if(!f)
	            {
	                st2.push(node);
	                st.pop();
	            }
	        }
	    }
	    vector<int>tran[n];
	    for(int i=0;i<n;i++){
	        for(auto &j:adj[i])
	        {
	            tran[j].push_back(i);
	        }
	    }
	    
	    stack<int>st3;
	    int ans{};
	    vector<int>vis2(n,0);
	    while(!st2.empty())
	    {
	        if(!vis2[st2.top()])
	        {
	            ans++;
    	        st3.push(st2.top());
    	        while(!st3.empty())
    	        {
    	            int node=st3.top();
    	            int f=0;
    	            vis2[node]=1;
    	            for(auto &j:tran[node])
    	            {
    	                if(!vis2[j])
    	                {
    	                    st3.push(j);
    	                    f=1;
    	                    break;
    	                }
    	            }
    	            if(!f)
    	            {
    	               // st2.push(node);
    	                st3.pop();
    	            }
    	        }
	        }
	        
    	        st2.pop();
	    }
	    
	    return ans;
	    
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends