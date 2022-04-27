class Solution {
public:
    int parent[100001],rank[100001];
    
    void makeset(int n)
    {
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }
    int findpar(int node)
    {
        if(parent[node]==node) return node;
        return parent[node]=findpar(parent[node]);
    }
    void makeunion(int u,int v)
    {
        u=findpar(u);
        v=findpar(v);
        
        if(rank[u]<rank[v])
        {
            parent[u]=v;
        }
        else if(rank[u]>rank[v])
        {
            parent[v]=u;
        }
        else
        {
            parent[u]=v;
            rank[u]++;
        }

        
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& v) {
        if(v.size()==0) return s;
        string ans;
        int n=s.size();
        makeset(n);
        for(auto &i:v)
        {
            int f=i[0],s=i[1];
            makeunion(f,s);
        }
        unordered_map<int,priority_queue<char,vector<char>,greater<char>>>m;
        for(int i=0;i<n;i++)
        {
            int par=findpar(i);
            m[par].push(s[i]);
        }
//         for(auto i:m)
//         {
//             cout<<i.first<<" ";
            
//         }
        for(int i=0;i<n;i++)
        {
            int par=findpar(i);
            ans.push_back(m[par].top());
            m[par].pop();
        }
        return ans;
    }
};