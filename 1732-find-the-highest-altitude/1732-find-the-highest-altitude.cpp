#define all(x) x.begin(),x.end()
class Solution {
public:
    int largestAltitude(vector<int>& v) {
    v.insert(v.begin(),0);
    int n=v.size();        

    for(int i=1;i<n;i++)
    {
        v[i]=v[i]+v[i-1];
    }
    // for(auto i:v)
    // {
    //     cout<<i<<" ";
    // }
    return *max_element(all(v));
    }
};