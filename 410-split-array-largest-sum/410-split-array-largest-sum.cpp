#define ll long long 
class Solution {
public:
    
    bool cando(vector<int>&v,ll int max_sum,int m)
    {
        ll int curr_sum=0;
        int k=1;
        
        for(int i=0;i<v.size();i++)
        {
            if(v[i]>max_sum) return 0;
            if(curr_sum+v[i]<=max_sum)
            {
                curr_sum+=v[i];
                    
                
            }
            else{
                k++;
                curr_sum=v[i];
            }
        }
        return k<=m;
    }
    
    int splitArray(vector<int>& v, int m) {
        int n=v.size();
        ll int l=0,r=n*1e6;
        
        while(l<r)
        {
            ll int mid=l+((r-l)/2);
            
            if(cando(v,mid,m))
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