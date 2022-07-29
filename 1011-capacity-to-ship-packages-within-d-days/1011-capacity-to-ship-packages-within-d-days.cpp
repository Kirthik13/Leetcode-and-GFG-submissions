class Solution {
public:
    bool cando(vector<int>&v,int max_cap,int days)
    {
        int curr_wt=0;
        int d=1;
        for(int i=0;i<v.size();i++)
        {
            if(max_cap<v[i]) return 0;
            
            curr_wt+=v[i];
            
            if(curr_wt>max_cap)
            {
                d++;
                curr_wt=v[i];
            }
            
            // if(days==0) return 0;
        
        }
        return d<=days;
        
    }
    int shipWithinDays(vector<int>& v, int days) {
        
        int l=0,r=accumulate(begin(v),end(v),0);
        
        while(l<r)
        {
            int mid=l+((r-l)/2);
            
            if(cando(v,mid,days))
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