class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // int n=gas.size(),f=0;
        int n=cost.size(),totf=0;
    
int tank{};
int ans{};
for(int i=0;i<n;i++)
{
    int curr=gas[i]-cost[i];
    tank+=curr;
    totf+=curr;
    if(tank<0)
    {
        ans=i+1;
        tank=0;
    }
}
        return totf<0?-1:ans;
    }
};