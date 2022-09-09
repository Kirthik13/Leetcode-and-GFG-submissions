class Solution {
public:
    bool canJump(vector<int>& v) {
        int n=v.size();
        int last=n-1;
        for(int i=n-2;i>=0;i--)
        {
            if(i+v[i]>=last) last=i;
        }
        return last<=0;
    }
};