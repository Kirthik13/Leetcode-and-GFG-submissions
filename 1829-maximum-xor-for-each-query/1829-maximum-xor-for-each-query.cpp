class Solution {
public:
    vector<int> getMaximumXor(vector<int>& v, int mb) {
        int r=pow(2,mb)-1;
        vector<int>pre(v.size(),0);
        pre[0]=v[0];
        for(int i=1;i<v.size();i++)
        {
            pre[i]=pre[i-1]^v[i];
        }
        vector<int>ans;
        for(int i=v.size()-1;i>=0;i--)
        {
            int c=r^pre[i];
            ans.push_back(c);
        }
        return ans;
            
    }
};