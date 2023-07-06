class Solution {
public:
    int minSubArrayLen(int tar, vector<int>& v) {
        int ans=INT_MAX,l{},curr{};
        for(int r=0;r<v.size();r++)
        {
            
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
       
        if(curr>=tar)
        {
            int n=v.size();
            ans=min(ans,n-l+1);
            // return ans;
        }
                
        return ans==INT_MAX?0:ans;
        
    }
};