#define ll long long
#define mod 1000000007

class Solution {
public:
     unordered_map<int, unordered_map<int,int>> dp;
    ll int fn(ll int st,ll int en,ll int k)
    {
        if(k==0)
        {
            if(st==en) return 1LL;
            return 0LL;
        }
        if(k<=0 || st+k < en || st-k > en) return 0;
        if(dp[st].count(k)) return dp[st][k];
        
        ll int call1=fn(st+1,en,k-1)%mod;
        ll int call2=fn(st-1,en,k-1)%mod;
        
        return dp[st][k]=(call1+call2)%mod;
        
    }
    int numberOfWays(int st, int en, int k) {
//         queue<pair<int,int>>q;
        
//         q.push({st,0});
//         int cnt{};
        
//         while(!q.empty())
//         {
//             int n=q.size();
//             for(int i=0;i<n;i++)
//             {
//                 auto node=q.front();
//                 q.pop();
//                 if(node.second==k)
//                 {
//                     if(node.first==en) cnt++;
                    
                        
//                 }
//                 else{
//                     q.push({node.first-1,node.second+1});
//                     q.push({node.first+1,node.second+1});
                    
//                 }
//             }
//         }
        // return cnt;
        
        // map<pair<ll int,ll int>,ll int>dp;
        return fn(st,en,k);
        
    }
};