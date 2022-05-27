class Solution {
public:
    int numberOfSteps(int n) {
        int c{};
        while(n)
        {
            if(n&1)
            {
                --n;
            }
            else{
                n/=2;
            }
            c++;
        }
        return c;
    }
};