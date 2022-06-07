class Solution {
public:
    void merge(vector<int>& v1, int m, vector<int>& v2, int n) {
       
        int l=m+n-1;
        m--;
        n--;
        while(m>=0 and n>=0)
        {
            v1[l]=max(v1[m],v2[n]);
            if(v1[m]>v2[n]) m--;
            else n--;
            
            l--;
        }
       
        while(n>=0)
        {
            v1[l]=v2[n];
            n--;
            l--;
        }
        
        
    }
};