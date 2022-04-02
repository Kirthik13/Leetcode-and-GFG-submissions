class Solution {
public:
    int minSubArrayLen(int target, vector<int>& v) {
         int sum{},st{},ans=INT_MAX;
    for(int i=0;i<v.size();i++)
    {
        sum+=v[i];
        
        while(sum>=target)
        {
          
            // if(sum==target){
            ans=min(ans,i-st+1);
            // }
            sum-=v[st];
            st++;
        }
        
    }
        return ans==INT_MAX?0:ans;
    }
};