class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& v) {
        
        if(v.size()==2) return 1;
        sort(begin(v),end(v));
        int prev=v[1]-v[0];
        for(int i=2;i<v.size();i++)
        {
            if(v[i]-v[i-1]!=prev) return 0;
        }
        return 1;
    }
};