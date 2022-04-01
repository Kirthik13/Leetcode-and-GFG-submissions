class Solution {
public:
    void reverseString(vector<char>& v) {
        int l=0,r=v.size()-1;
        while(l<r)
        {
            swap(v[l++],v[r--]);
        }
        // return v;
            
    }
};