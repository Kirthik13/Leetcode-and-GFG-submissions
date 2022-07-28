class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        
        int m=v1.size(),n=v2.size();
        if(n<m) return findMedianSortedArrays(v2,v1);

        int l=0,r=m;
        
        while(l<=r)
        {
            int cut1=(l+r)/2;
            int cut2=(m+n+1)/2-cut1;
           
            int l1=(cut1-1>=0)?v1[cut1-1]:INT_MIN;
            int l2=(cut2-1>=0)?v2[cut2-1]:INT_MIN;
            
            int r1=(cut1<m)?v1[cut1]:INT_MAX;
            int r2=(cut2<n)?v2[cut2]:INT_MAX;

         
            if(l1<=r2 and l2<=r1)
            {
                if((m+n)%2==0)
                {
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
                return max(l1,l2);

            }
            else if(l1>r2)
            {
                r=cut1-1;
            }
            else{
                l=cut1+1;

            }
                
        }
        return 0.0;
        
    }
};