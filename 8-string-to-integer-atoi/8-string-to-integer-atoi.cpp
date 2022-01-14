class Solution {
public:
    int myAtoi(string s) {
        
        stringstream ss(s);
        int g=0;
        ss>>g;
        return g;
    }
};