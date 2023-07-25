class Solution {
public:
    int peakIndexInMountainArray(vector<int>& v) {
        int i{},n=v.size();
        while(i<n-1)
        {
            if(!(v[i]<v[i+1]))
            {
                i++;
                break;
            }
            i++;
        }
        int ans=i-1;
        
        while(i<n)
        {
            if(!(v[i]>v[i-1]))
            {
                break;
            }
            i++;
        }
        
         return ans;
        
    }
};