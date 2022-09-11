#define mod 1000000007
#define ll long long
class Solution {
public:
    int maxPerformance(int n, vector<int>& sp, vector<int>& eff, int k) {
        
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++)
        {
            v[i]={eff[i],sp[i]};
        }
        
        sort(rbegin(v),rend(v));
        
        priority_queue<int,vector<int>,greater<int>>pq;
        
        ll sums{};
        ll res{};
        for(auto &i:v)
        {
            ll cursp=i.second;
            ll cureff=i.first;
            
            sums+=cursp;
            
            pq.push(cursp);
            
            while(pq.size()>k)
            {
                sums-=pq.top();
                pq.pop();
            }
            
            res=max(res,sums*cureff);
        }
        
        return res%mod;
        
    }
};