class Solution {
public:
    int maxArea(vector<int>& v) {
        int l=0,r=v.size()-1;
        int ans=INT_MIN;
        while(l<r)
        {
            if(v[l]>=v[r])
            {
                int bred=r-l;
                int len=v[r];
                
                ans=max(ans,bred*len);
                r--;
            }
            else{
                
                int bred=r-l;
                int len=v[l];
                
                ans=max(ans,bred*len);
                l++;
            }
        }
        return ans;
    }
};