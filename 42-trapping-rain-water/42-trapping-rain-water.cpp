class Solution {
public:
    int trap(vector<int>& v) {
        int n=v.size(),ans{};
        int l{},r=n-1;
        int lmax{},rmax{};
        while(l<=r)
        {
            if(v[l]<=v[r])
            {
                if(lmax<v[l])
                {
                    lmax=v[l];
                    
                }
                else{
                    ans+=(lmax-v[l]);
                }
                l++;
            }
            else{
                 if(rmax<v[r])
                {
                    rmax=v[r];
                    
                }
                else{
                    ans+=(rmax-v[r]);
                }
                r--;
            }
        }
       
        
        return ans;
    }
};