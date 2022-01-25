class Solution {
public:
    bool validMountainArray(vector<int>& v) {
        int i=0,n=v.size();
        if(n==1)
        {
            return 0;
        }
        
        while(i<n-1 )
        {
            if( v[i]<v[i+1]){
            i++;
            }
            else if(v[i]==v[i+1]){
                return 0;
            }
            else{
                break;
            }
        }
        int j=i;
        if(i==0 or i==n-1)
        {
           return 0; 
        }
        while(j<n-1 and v[j]>v[j+1])
        {
            j++;
        }
        if(j==n-1)
        {
            return 1;
        }
        return 0;
    }
};