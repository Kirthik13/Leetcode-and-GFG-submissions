class Solution {
public:
    int longestSubarray(vector<int>& v) {
        int n=v.size();
        int l{},ans=0,nofzero{};
        
        for(int r=0;r<n;r++)
        {
            if(v[r]==0)
            {
                nofzero++;
            }
            
            while(nofzero>1)
            {
                if(v[l]==0)
                {
                    nofzero--;
                }
                l++;

            }
            ans=max(ans,r-l);
           
        }
        return ans;
    }
};