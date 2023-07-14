class Solution {
public:
    int longestSubsequence(vector<int>& v, int diff) {
        int n=v.size();
        int ans{};
        map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[v[i]]=1+m[v[i]-diff];
            ans=max(ans,m[v[i]]);
        }
        return ans;
    }
};