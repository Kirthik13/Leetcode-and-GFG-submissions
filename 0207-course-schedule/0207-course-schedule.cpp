class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>>v(n);
        for(auto &i:pre)
        {
            v[i[0]].push_back(i[1]);
        }
        
        vector<int>in(n);
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            for(auto &it:v[i])
            {
                in[it]++;
            }
           
        }
        
        for(int i=0;i<n;i++)
        {
             if(in[i]==0)
            {
                q.push(i);
            }
        }
        
        
        
        int c{};
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            
            for(auto &i:v[node])
            {
                in[i]--;
                if(in[i]==0)
                {
                    q.push(i);
                }
            }
            c++;
        }
        
        return c==n;
        
        
        
        
    }
};