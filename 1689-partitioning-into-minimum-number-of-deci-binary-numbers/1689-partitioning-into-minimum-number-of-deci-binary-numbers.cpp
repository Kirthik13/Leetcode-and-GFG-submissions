class Solution {
public:
    int minPartitions(string n) {
        int ans=INT_MIN;
        for(int i=0;i<n.size();i++)
        {
            int g=int(n[i])-48;
            ans=max(g,ans);
        }
        return ans;
    }
};