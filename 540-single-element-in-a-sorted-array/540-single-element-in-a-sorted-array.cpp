class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        int n=v.size();
        int l=0,r=n-1,ans{};
        while(l<=r)
        {
            int mid=(l+r)/2;
            
            
            
            if((mid%2==0 and mid+1<n and v[mid]==v[mid+1]) or (mid%2!=0 and mid-1>=0 and v[mid]==v[mid-1]))
            {
                l=mid+1;   
            }
            else{
                ans=v[mid];
                r=mid-1;
            }
            
        }
        return ans;
    }
};