class Solution {
public:
    bool isPowerOfTwo(long long int n) {
        if(n<=0)
        {
            return 0;
        }
        // if((n&(n-1)) == 0)
        // {
        //     return 1;
        // }
        
        return ceil(log2(n))==floor(log2(n));
    }
};