class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& v, int k) {
        int prod=1,ans{},l{};
        for(int r=0;r<v.size();r++)
        {
            prod*=v[r];
            // if(prod>=k){
            while(prod>=k and l<=r)
            {
                prod/=v[l];
                l++;
            }
            // }
            ans+=(r-l+1);
        }
        return ans;
    }
};