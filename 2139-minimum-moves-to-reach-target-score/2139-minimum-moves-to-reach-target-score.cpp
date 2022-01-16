class Solution {
public:
    int minMoves(int target, int md) {
        int c{};

while(target>1 and md>0)
{
    c=c+target%2+1;
    md--;
    target=target/2;
    
}
        
int diff=target-1;
return c+diff;
    }
};