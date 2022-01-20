#define all(v) v.begin(),v.end()
class Solution {
public:
    int caneat(vector<int>& v,int &k,int &h)
    {
        
        int n=v.size();
     
        int nh=0;

      
        int i=0;
        
        while(i<n)
        {
         

           nh=nh+ceil(1.0*v[i]/k);
            if(nh>h)
            {
                return 0;
            }
            i++;
        }
     
        return nh<=h;
            
    }
            
    // }
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