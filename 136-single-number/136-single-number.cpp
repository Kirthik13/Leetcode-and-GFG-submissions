class Solution {
public:
    int singleNumber(vector<int>& v) {
        int x=0;
        for(auto &i:v)
        {
            x^=i;
        }
        return x;
    }
};