class Solution {
public:
    int thirdMax(vector<int>& v) {
       set<int,greater<int>>st(begin(v),end(v));
        
        auto it=st.begin();
        advance(it,2);
        if(it!=st.end()) return *it;
        return *st.begin();
        
    }
};