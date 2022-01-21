class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // int n=gas.size(),f=0;
        int n=cost.size(),totf=0,totc{};
for(int i=0;i<n;i++)
{
    totf+=gas[i];
    totc+=cost[i];
}
if(totf<totc)
{
    // cout<< -1;
    return -1;
}

int currf{};
int ans{};
for(int i=0;i<n;i++)
{
    if(currf<0)
    {
        ans=i;
        currf=0;
    }
    currf+=(gas[i]-cost[i]);
}
        return ans;

        
    }
};