class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        
        vector<int>in(n,0);
        vector<vector<int>>v(n);
        queue<int>q;
        for(auto &i:pre)
        {
            int a=i[0],b=i[1];
            v[b].push_back(a);
        }
        
        for(int i=0;i<n;i++)
        {
            for(auto &it:v[i])
            {
                in[it]++;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(in[i]==0) q.push(i);
        }
        
        int c{};
        
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            
            for(auto &it:v[node])
            {
                in[it]--;
                if(in[it]==0) q.push(it);
            }
            
            c++;
        }
        if(c==n) return 1;
        return 0;
    }
};