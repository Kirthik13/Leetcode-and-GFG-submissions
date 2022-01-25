class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s=to_string(n);
        sort(begin(s),end(s));
        for(int i=0,p=1;i<30;i++,p<<=1)
        {
            string pow2=to_string(p);
            sort(begin(pow2),end(pow2));
            if(s==pow2) return 1;
        }
        return 0;
    }
};