class Solution {
public:
    int hammingWeight(uint32_t n) {
        int c{};
        while(n)
        {
            // cout<<"n : "<<n<<endl;
            uint32_t b=1;
            if(n&b) c++;
            n>>=1;
            // cout<<"n2 : "<<n<<endl;

        }
        return c;
    }
};