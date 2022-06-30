class Solution {
public:
    int minMoves2(vector<int>& v) {
        int l=0,r=v.size()-1,cnt{};
        sort(begin(v),end(v));
        while(l<r)
        {
            cnt+=(v[r]-v[l]);
            l++;
            r--;
        }
        return cnt;
    }
};