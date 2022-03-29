class Solution {
public:
    int search(vector<int>& v, int target) {
        int l=0;
        int r=v.size()-1;
        
        while(l<=r)
        {
            int mid=(l+r)/2;
            
            if(v[mid]==target)
            {
                return mid;
            }
            if(v[l]<=v[mid])
            {
                if(target>=v[l] and target<=v[mid])
                {
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{
                
                if(target>=v[mid+1] and target<=v[r])
                {
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
        }
        return -1;
    }
};