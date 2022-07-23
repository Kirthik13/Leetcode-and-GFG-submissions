class Solution {
public:
    map<int,int>m;
    void totmerge(vector<pair<int, int> >&v,int l,int r,vector<int>&counts)
    {
        int mid=(l+r)/2;
        int l1=l;
        int l2=mid+1;
            int idx{};
        vector<pair<int, int> > curr(r-l+1);
        while(l1<=mid and l2<=r)
        {
            if(v[l1].first<=v[l2].first)
            {

                curr[idx]=v[l2];
                
                
                l2++;
                idx++;
            }
            else{
                 counts[v[l1].second] +=( r - l2 + 1);
                
                curr[idx]=v[l1];
                
                l1++;
                idx++;
            }
        }
        
        while(l1<=mid)
        {
            curr[idx]=v[l1];
                
                l1++;
                idx++;
        }
        while(l2<=r)
        {
         curr[idx]=v[l2];
                
                
                l2++;
                idx++;   
        }
        
         idx=0;
        for(int i=l;i<=r;i++)
        {
            v[i]=curr[idx];
            idx++;
        }
        
        
        
        
    }
    void merge(vector<pair<int, int> >&v,int l,int r,vector<int>&counts)
    {
        if(l>=r) return ;
        
        int mid=(l+r)/2;
        merge(v,l,mid,counts);
        merge(v,mid+1,r,counts);
        
        totmerge(v,l,r,counts);
        
        
        
    }
    vector<int> countSmaller(vector<int>& arr) {
        int n=arr.size();
        vector<int>counts(n);
        vector<pair<int, int> > v(n);
        for (int i = 0; i < n; i++)   
            v[i] = make_pair(arr[i], i);
            
        merge(v,0,n-1,counts);
       
        return counts;
        
    }
};