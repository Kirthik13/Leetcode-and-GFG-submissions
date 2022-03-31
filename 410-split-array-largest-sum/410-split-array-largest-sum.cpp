class Solution {
public:
    bool cando(vector<int>&v,int &k,int &mid)
    {
        int curr{},nos=1;
        for(int i=0;i<v.size();i++)
        {
            curr+=v[i];
            if(v[i]>mid) return 0;
            if(curr>mid)
            {
               curr=v[i];
                nos++;
                if(nos>k) return 0;
            }
        }
    return 1;
    }
    int splitArray(vector<int>& v, int k) {
        int l=0,r=accumulate(begin(v),end(v),0);
        int ans=INT_MAX;
        while(l<=r)
        {
            int mid=(r+l)/2;
            // cout<<"mid : "<<mid<<endl;
            if(cando(v,k,mid))
            {
                ans=min(ans,mid);
                // cout<<"ans : "<<ans<<endl;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
            
        }
        return ans;
    }
};