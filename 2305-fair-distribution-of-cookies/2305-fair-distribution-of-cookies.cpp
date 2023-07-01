class Solution {
public:
    int ans=INT_MAX;
    void fn(vector<int>& v,int idx,int n,vector<int>&subst) 
    {
        if(idx==n)
        {
            int currmax=*max_element(begin(subst),end(subst));
            ans=min(currmax,ans);
            return;
        }
        
        for(int i=0;i<subst.size();i++)
        {
            subst[i]+=v[idx];
            fn(v,idx+1,n,subst);
            subst[i]-=v[idx];
            
        }
    }
    int distributeCookies(vector<int>& v, int k) {
        int n=v.size();
        vector<int>subst(k);
        fn(v,0,n,subst);
        return ans;
    }
};