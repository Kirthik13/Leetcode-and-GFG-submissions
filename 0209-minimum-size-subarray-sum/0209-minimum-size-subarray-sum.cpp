class Solution {
public:
    int minSubArrayLen(int tar, vector<int>& v) {
        int ans=INT_MAX,l{},curr{};
        for(int r=0;r<=v.size();r++)
        {
            if(r==v.size() )
            {
                if(curr>=tar)
                {
                 ans=min(ans,r-l+1);
                 return ans;
                }
                break;
                
            }
            curr+=v[r];
            // if(curr>=tar)
            // {
            //       ans=min(ans,r-l+1);
            // }
            while(curr>=tar and l<=r)
            {
                ans=min(ans,r-l+1);
                curr-=v[l];
                l++;
            }
        }
        return ans==INT_MAX?0:ans;
        
    }
};