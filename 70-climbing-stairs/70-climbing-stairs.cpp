class Solution {
public:
    int climbStairs(int n) {
        int prev=1,nextprev=1;
        for(int i=n-2;i>=0;i--)
        {
            int curr=prev+nextprev;
            nextprev=prev;
            prev=curr;
        }
        return prev;
    }
};