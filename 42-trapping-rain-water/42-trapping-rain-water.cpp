class Solution {
public:
    int trap(vector<int>& v) {
        int n=v.size(),ans{};
        
        vector<int>pre(n,0);
        vector<int>suf(n,0);
        pre[0]=v[0];
        suf[n-1]=v[n-1];
        
        for(int i=1;i<n;i++)
        {
            pre[i]=max(v[i],pre[i-1]);
        }
        
        for(int i=n-2;i>=0;i--)
        {
            suf[i]=max(v[i],suf[i+1]);
        }
        

        
        for(int i=0;i<n;i++)
        {
            ans+=(min(pre[i],suf[i])-v[i]);
        }
        return ans;
    }
};