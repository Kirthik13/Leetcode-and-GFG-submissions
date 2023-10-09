class Solution {
public:
    vector<int> searchRange(vector<int>& v, int tar) {
        if(binary_search(begin(v),end(v),tar))
        {
        int idx1=lower_bound(begin(v),end(v),tar)-begin(v);
        int idx2=upper_bound(begin(v),end(v),tar)-begin(v);
        
        if(idx1>=v.size()) return {-1,-1};
            
        return {idx1,idx2-1};
        }
        return {-1,-1};
        
    }
};