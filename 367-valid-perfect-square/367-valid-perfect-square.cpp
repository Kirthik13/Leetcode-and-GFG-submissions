class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int l=1,r=1<<31-1;
        
        while(l<r)
        {
            long long int mid=l+((r-l)/2);
            
            if(mid*mid==num)
            {
                return true;
            }
            else if(mid*mid>num)
            {
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        if(l*l==num) return 1;
        return 0;
    }
};