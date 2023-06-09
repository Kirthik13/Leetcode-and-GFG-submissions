class Solution {
public:
    char nextGreatestLetter(vector<char>& v, char target) {
        auto it=upper_bound(begin(v),end(v),target);
        if(it==v.end()) return v.front();
        return v[it-v.begin()];
    }
};