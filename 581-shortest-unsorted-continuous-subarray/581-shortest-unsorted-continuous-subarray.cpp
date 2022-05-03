class Solution {
public:
    int findUnsortedSubarray(vector<int>& v) {
//         vector<int>v2(begin(v),end(v));
//         sort(begin(v2),end(v2));
//         int l=0,r=v.size()-1;
//         while(l<v.size()-1 and v2[l]==v[l]) l++;
//         while(r>0 and v2[r]==v[r]) r--;
        
//         if(l==v.size() or r==0) return 0;
//         return r-l+1;
        int n=v.size();
        vector<int>minr(n);
        vector<int>maxl(n);
        
        int max_sf=INT_MIN;

        for(int i=0;i<n;i++)
        {
            maxl[i]=max_sf=max(max_sf,v[i]);
        }

         int min_sf=INT_MAX;
        for(int i=n-1;i>=0;i--)
        {
            minr[i]=min_sf=min(min_sf,v[i]);
        }
      
        
        int i=0,j=n-1;
       while (i < n && v[i] <= minr[i]) i++;
        while (j > i && v[j] >= maxl[j]) j--;
       
        
        return j-i+1;
    }
};