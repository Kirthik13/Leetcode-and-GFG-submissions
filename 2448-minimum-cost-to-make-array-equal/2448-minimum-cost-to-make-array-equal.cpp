#define ll long long 
class Solution {
public:
    ll calculateans(vector<pair<ll int,ll int>>& v, vector<int>& cost,int medianele) {
        ll ans{};
        for(int i=0;i<v.size();i++)
        {
            ans=ans+(abs(v[i].first-medianele)*v[i].second);
        }
        return ans;
    }
    long long minCost(vector<int>& v2, vector<int>& cost) {
        int n=v2.size();
        vector<pair<ll int,ll int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({v2[i],cost[i]});
        }
        sort(begin(v),end(v));
        ll totnos{},curr{};
        for(auto &i:v)
        {
            totnos+=i.second;
        }
        int i{};
       // cout<<totnos<<" "<<(totnos+1)/2<<endl;
        if(totnos&1)
        {
            while(i<n and curr<(totnos+1)/2)
            {
                curr+=v[i].second;
                // cout<<curr<<endl;
                i++;
            }
        }
        else{
            while(i<n and curr<(totnos)/2)
            {
                curr+=v[i].second;
                // cout<<curr<<endl;
                i++;
            }
        }
        return calculateans(v,cost,v[i-1].first);

    }
};