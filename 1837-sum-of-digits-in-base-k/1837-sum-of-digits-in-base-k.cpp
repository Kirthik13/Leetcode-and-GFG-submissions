class Solution {
public:
    int sumBase(int n, int k) {
        int ans=0;
        
        while(n>=k)
        {
            int rem=n%k;
            ans*=10;
            ans+=rem;
            n/=k;
        }
        
        if(n>0)
        {
            
            ans*=10;
            ans+=n;
            n/=k;
        }
        
        int g{};
        while(ans)
        {
            int rem=ans%10;
            ans/=10;
            g+=rem;
        }
        return g;
    }
};