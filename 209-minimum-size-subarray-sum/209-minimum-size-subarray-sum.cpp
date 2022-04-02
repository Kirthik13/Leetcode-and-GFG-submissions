class Solution {
public:
    int minSubArrayLen(int target, vector<int>& v) {
         int sum{},st{},ans=INT_MAX;
    for(int i=0;i<v.size();i++)
    {
        sum+=v[i];
        
        while(sum>=target)
        {
            // if(i!=k-1){
            // cout<<" i : "<<i<<endl;
            // }
            // cout<<" sum : "<<sum<<endl;
            ans=min(ans,i-st+1);
            sum-=v[st];
            st++;
        }
        
    }
        return ans==INT_MAX?0:ans;
    }
};