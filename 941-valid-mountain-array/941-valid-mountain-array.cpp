class Solution {
public:
    bool validMountainArray(vector<int>& v) {
        int i=0,n=v.size(),j=n-1;
        if(n==1)
        {
            return 0;
        }
        while(i<n-1 and v[i]<v[i+1])
        {
            i++;
        }
       
         while(j>0 and v[j]<v[j-1])
        {
            j--;
        }
        return i>0 and i==j and j<n-1;
    }
};