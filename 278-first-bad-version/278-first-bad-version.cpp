// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
       long long int l=1;
        long long int r=((long long)1<<31)-1;
        long long int ans=LONG_LONG_MAX;
        
        
        while(l<r)
        {
            long long int mid=l+((r-l)/2);
            
            if(isBadVersion(mid))
            {
                r=mid;
                ans=min(ans,mid);
            }
            else{
                l=mid+1;
            }
        }
        if(isBadVersion(l))
        {
            ans=min(ans,l);
        }
        return ans;
    }
};
