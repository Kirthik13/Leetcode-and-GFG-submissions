#define all(v) v.begin(),v.end()
class Solution {
public:
    int caneat(vector<int> v,int &k,int &h)
    {
        int n=v.size(),cnt{};
         for(int i=0; i<n; i++) {
            cnt += ceil(1.0 * v[i]/k);
            if(cnt > h) return false;
        }
        return 1;
            
    }
    int minEatingSpeed(vector<int>& v, int h) {
         int n=v.size();
        int r=*max_element(all(v));
        int l=1;
        int ans=INT_MAX;
        while(l<=r)
        {
            int mid=(l+r)/2;
            // deb(mid);
            if(caneat(v,mid,h))
            {
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};