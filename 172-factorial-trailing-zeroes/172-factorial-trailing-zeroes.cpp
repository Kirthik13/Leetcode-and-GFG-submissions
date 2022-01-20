class Solution {
public:
    int fn(int n)
{
    int c{};
    int i=5;
    while(n/i>0)
    {
        c=c+n/i;
        i*=5;
    }
    return c;
}
    int trailingZeroes(int n) {
        return fn(n);
    }
};