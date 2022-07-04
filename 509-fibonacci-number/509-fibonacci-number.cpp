class Solution {
public:
    int fib(int n) {
        
        if(n<=1) return n;
        int prev=1,nextprev=0;
        for(int i=2;i<=n;i++)
        {
            int curr=prev+nextprev;
            nextprev=prev;
            prev=curr;
            
            
        }
        return prev;
        
    }
};