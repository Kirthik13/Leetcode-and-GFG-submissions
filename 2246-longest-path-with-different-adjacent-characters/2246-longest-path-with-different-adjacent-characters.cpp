class Solution {
public:
    int res=INT_MIN;
    int dfs(  vector<vector<int>>&child,string &s,int &res,int i)
    {
        int big1=0,big2=0;
        for(auto &j:child[i])
        {
            int curr=dfs(child,s,res,j);

            if(s[i]==s[j]) continue;
            if(curr>big2) big2=curr;
            if(big1<big2) swap(big1,big2);
        }
        res=max(res,(big1+big2+1));
        return big1+1;
    }
    int longestPath(vector<int>& v, string s) {
        int n=s.size();
        vector<vector<int>>child(n,vector<int>());
        
        for(int i=1;i<v.size();i++)
        {
            child[v[i]].push_back(i);
        }
        dfs(child,s,res,0);
        return res;
    }
};