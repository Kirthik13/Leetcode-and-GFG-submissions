class Solution {
public:
    vector<int> toposort( vector<vector<int>>&graph)
    {
        int n=graph.size();        
        vector<int>indeg(n);
        for(int i=0;i<n;i++)
        {
            for(auto &node:graph[i])
            {
                indeg[node]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto &i:graph[node])
            {
                
                    indeg[i]--;
                    if(indeg[i]==0)
                    {
                        q.push(i);
                    }
                
            }
        }
        
        return ans;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rcond, vector<vector<int>>& ccond) {
        
        vector<vector<int>>graph1(k);
        vector<vector<int>>graph2(k);
        
        vector<vector<int>>totans(k,vector<int>(k));
        for(auto &i:rcond)
        {
            graph1[i[0]-1].push_back(i[1]-1);
        }
        for(auto &i:ccond)
        {
            graph2[i[0]-1].push_back(i[1]-1);
        }        
        
        vector<int>temp1;
        vector<int>temp2;
        
     
        
        
      
        temp1=toposort(graph1);
    
        temp2=toposort(graph2);
       
        
        if(temp2.size()!=k or temp1.size()!=k) return {};
        
        // reverse(begin(temp1),end(temp1));
        // reverse(begin(temp2),end(temp2));
        
        
        for(int i=0;i<temp1.size();i++)
        {
            for(int j=0;j<temp2.size();j++)
            {
                if(temp1[i]==temp2[j])
                {
                    totans[i][j]=temp1[i]+1;
                }
            }
            
            
        }
        
        // for(auto &i:temp1) cout<<i+1<<" ";
        // cout<<endl<<endl;
        // for(auto &i:temp2) cout<<i+1<<" ";
        
        return totans;
        
        
    }
};