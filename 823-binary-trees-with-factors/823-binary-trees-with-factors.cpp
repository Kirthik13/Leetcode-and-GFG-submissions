#define ll long long
#define mod 1000000007
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& v) {
        unordered_map<ll,ll>m;
        sort(begin(v),end(v));
        m[v[0]]=1;
        for(int i=1;i<v.size();i++)
        {
            ll cnt=1;
            
            for(auto &j:m)
            {
                ll el=j.first;
                if(m.find(v[i]/el)!=m.end() and v[i]%el==0)
                {
                    cnt+=(m[v[i]/el]*m[el])%mod;
                }
            }
            m[v[i]]=cnt;
        }
       ll int noOfTrees = 0;
        for(auto i : m){
            noOfTrees = (noOfTrees + i.second) % mod;
        }
        return noOfTrees;
        
    }
};