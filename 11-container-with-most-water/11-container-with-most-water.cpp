class Solution {
public:
    int maxArea(vector<int>& v) {
        int n=v.size();
        int l=0,r=n-1,ans{};
        
        while(l<r)
        {
            if(v[l]>=v[r])
            {
                int wid=r-l;
                ans=max(v[r]*wid,ans);
                r--;
            }
            else{
                int wid=r-l;                
                ans=max(v[l]*wid,ans);

                l++;
            }
        }
        
        return ans;
    }
};