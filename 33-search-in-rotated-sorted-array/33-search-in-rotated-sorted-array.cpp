class Solution {
public:
    int search(vector<int>& v, int target) {
        int n=v.size();
        // if(n==1)
        // {
        //     return v[0]==target?0:-1;
        // }
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid=l+((r-l)/2);
            if(v[mid]==target)
            {
                return mid;
            }
            else if(v[l]<=v[mid])
            {
                if(v[l]<=target and v[mid]>=target)
                {
                                        r=mid-1;

                }
                else{
                                        l=mid+1;

                }
            }
            else
            {
                 if(v[r]>=target and v[mid+1]<=target )
                {
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            // cout<<"l : "<<l<<" r : "<<r<<" m : "<<mid<<endl;
        }
        return -1;
    }
};