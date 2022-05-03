class Solution {
public:
    int findUnsortedSubarray(vector<int>& v) {
        vector<int>v2(begin(v),end(v));
        sort(begin(v2),end(v2));
        int l=0,r=v.size()-1;
        while(l<v.size()-1 and v2[l]==v[l]) l++;
        while(r>0 and v2[r]==v[r]) r--;
        
        if(l==v.size() or r==0) return 0;
        return r-l+1;

        
    }
};