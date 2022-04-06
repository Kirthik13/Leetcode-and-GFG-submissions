#define mod 1000000007
class Solution {
public:
    int threeSumMulti(vector<int>& v, int target) {
        unordered_map<long long,long long>m;
        int ans{};
        for(int i=0;i<v.size();i++)
        {
            ans=(ans+m[target-v[i]])%mod;
            
            for(int j=0;j<i;j++)
            {
                m[v[i]+v[j]]++;
            }
        }
        return ans%mod;
    }
};