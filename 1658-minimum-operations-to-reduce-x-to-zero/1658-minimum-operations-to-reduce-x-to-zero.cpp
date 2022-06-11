class Solution {
public:
    int minOperations(vector<int>& v, int x) {
        unordered_map<int,int>left;
        int sum{},ans=INT_MAX;
        int i;
        for(i=0;i<v.size() and sum<=x ;i++)
        {
            left[sum]=i;
            sum+=v[i];
        }
        if(sum<=x) left[sum]=i;
        int n=v.size();
        sum=0;
        for(int i=n-1;i>=0 and sum<=x ;i--)
        {
            auto it=left.find(x-sum);
            if(it!=left.end() and i+1>=it->second)
            {
                ans=min(ans,n-i-1+it->second);
            }
            sum+=v[i];
        }
        return ans==INT_MAX?-1:ans;
    }
};