class Solution {
public:
    int threeSumClosest(vector<int>& v, int target) {
        sort(begin(v),end(v));
        int leastdiff=INT_MAX;
        int ans=INT_MAX;
        for(int i=0;i<v.size()-2;i++)
        {
            int j=i+1;
            int k=v.size()-1;
            while(j<k)
            {
                if(v[i]+v[j]+v[k]==target)
                {
                    return target;
                }
                if(abs(v[i]+v[j]+v[k]-target)<=leastdiff)
                {
                    leastdiff=abs(v[i]+v[j]+v[k]-target);
                    ans=    v[i]+v[j]+v[k];
                    
                }
                    
               
                if(v[i]+v[j]+v[k]>=target)
                {
                    k--;
                    
                }
                else
                {
                    j++;
                }
                
            }
            
        }
        return ans;
    }
};