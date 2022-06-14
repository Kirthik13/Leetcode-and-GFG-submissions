class Solution {
public:
 
   
    vector<int> findOrder(int n, vector<vector<int>>& v) {
        
        vector<vector<int>>g(n);
        vector<int>in(n);

     

        for(auto &i:v)
        {
            int c=i[0],fc=i[1];
           
            g[fc].push_back(c);
            in[c]++;
            
        }
    
       
     
  
        queue<int>q;
       
    for(int i=0;i<n;i++)
    {
        if(!in[i])
        {
            q.push(i);
           
        }
    }
        
        vector<int>ans;
        // cout<<q.front()<<endl;
        while(!q.empty())
        {
            int el=q.front();
            ans.push_back(el);
            q.pop();
            
            for(auto &it:g[el])
            {
                if(--in[it]==0)
                {
                    q.push(it);
                }
            }
        }
        if(ans.size()==n)  return ans;
        return {};
    }
};