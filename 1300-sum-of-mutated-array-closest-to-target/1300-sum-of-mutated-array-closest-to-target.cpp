class Solution {
public:
    int cando(vector<int>&v,int max_val,int target)
    {
        
        int sum{};
        for(int i=0;i<v.size();i++)
        {
            if(v[i]>max_val)
            {
                sum+=max_val;
            }
            else{
                sum+=v[i];
            }
            
        }
        
       return sum;
    }
    int findBestValue(vector<int>& v, int target) {
        
        int l=0,r=*max_element(begin(v),end(v));
        
        int leftmin=INT_MAX,leftbest{};
        int rightmin=INT_MAX,rightbest{};
        
        
        
        
        while(l<=r)
        {
            int mid=l+((r-l)/2);
            int sum=cando(v,mid,target);
            if(sum<target)
            {
                if(abs(sum-target)<=leftmin)
                {
                    leftmin=abs(sum-target);
                    leftbest=mid;
                }
                l=mid+1;
            }
            else{
               if(abs(sum-target)<=rightmin)
                {
                    rightmin=abs(sum-target);
                    rightbest=mid;
                }
                r=mid-1;
            }
            
        }
        return (leftmin<=rightmin)?leftbest:rightbest;
    }
};