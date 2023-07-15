#define ll  long long 
class Solution {
public:
    map<pair<ll int,pair<ll int,ll int>>,int>m;
    int fn(vector<vector<int>>& v,int idx,int n,int k,ll int en) 
    {
        if(idx>=n or k==0)
        {
            return 0;
        }
        
        if(m.find({idx,{k,en}})!=m.end())
        {
            return m[{idx,{k,en}}];
        }
        
        ll int ans1{},ans2{};
        if(( en==-1) or(en<v[idx][0]))
        {
            ans1=v[idx][2]+fn(v,idx+1,n,k-1,v[idx][1]);
        }
        ans2=fn(v,idx+1,n,k,en);
        
        return m[{idx,{k,en}}]=max(ans1,ans2);
    }
    int maxValue(vector<vector<int>>& v, int k) {
        int n=v.size();
        sort(begin(v),end(v));
        return fn(v,0,n,k,-1);
    }
};