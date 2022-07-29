#define ll long long
class Solution {
public:
    const ll lmax=1e9;
    
    bool cando(vector<int>&v,ll max_time,int nob,int k)
    {
        int curr_b=0;
        
        int curr_fl=0;
        for(int i=0;i<v.size();i++)
        {
            if(max_time<v[i] and curr_fl!=0)
            {
                if(curr_fl==k)
                {
                    curr_b++;
                    // curr_fl=0;
                }
                curr_fl=0;
                
                continue;
            }
            if(v[i]<=max_time)
            {
                curr_fl++;
                
            }
            if(curr_fl==k)
            {
                curr_b++;
                curr_fl=0;
            }
        }
        
        return curr_b>=nob;
        
    }
    
    int minDays(vector<int>& v, int m, int k) {
        
        int n=v.size();
        
        if(n < (m*k)) return -1;
        
        ll int l=1,r=*max_element(begin(v),end(v));
        
        while(l<r)
        {
            ll mid=l+((r-l)/2);
            
            if(cando(v,mid,m,k))
            {
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
        
    }
};