class Solution {
public:
    int maxSubArray(vector<int>& v) {
        
        int sum{},maxsf=INT_MIN;
        for(int i=0;i<v.size();i++)
        {
            sum+=v[i];

            if(sum<v[i]) sum=v[i];
            
            maxsf=max(maxsf,sum);
            
        }
        return maxsf;
    }
};