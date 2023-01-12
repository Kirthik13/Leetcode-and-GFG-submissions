class Solution {
public:
    void dfs(vector<vector<int>>& v, string &s,int node, int cnt[],vector<int>&vis,  vector<int>&totans) 
    {
        vis[node]=1;
        
        for(auto &i:v[node])
        {
            if(!vis[i])
            {
                // map<char,int>m1;
                 int cnt1[26] = {};
                dfs(v,s,i,cnt1,vis,totans);
                for(int k=0;k<26;k++)
                {
                    cnt[k]+=cnt1[k];
                }
                // for(auto &i:m1)
                // {
                //     if(m.find(i.first)!=m.end())
                //     {
                //         m[i.first]+=m1[i.first];
                //     }
                // }
            }
        }
        // m[s[node]]++;
        totans[node]=++cnt[s[node]-'a'];
        
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string s) {
        vector<vector<int>>v(n);
        for(auto &i:edges)
        {
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
            
        }
        
        // map<char,int>m;
        vector<int>vis(n);
            vector<int>totans(n);
        int cnt[26]={0};
        dfs(v,s,0,cnt,vis,totans);
        return totans;
    }
};