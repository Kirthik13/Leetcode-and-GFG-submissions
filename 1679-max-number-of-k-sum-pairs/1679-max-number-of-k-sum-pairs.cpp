class Solution {
public:
    int maxOperations(vector<int>& v, int k) {
        sort(begin(v),end(v));
        int l=0,r=v.size()-1,ans{};
        while(l<r)
        {
            if(v[l]+v[r]<k)
            {
                l++;
            }
            else if(v[l]+v[r]>k)
            {
                r--;
            }
            else
            {
                l++;
                r--;
                ans++;
            }
        }
        return ans;
    }
};