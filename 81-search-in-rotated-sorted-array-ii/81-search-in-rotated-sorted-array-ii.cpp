class Solution {
public:
    bool search(vector<int>& v, int target) {
        int l=0,r=v.size()-1;
          while(l<=r)
        {
            int mid=(l+r)/2;
            // cout<<"mid : "<<mid<<endl;
            if(v[mid]==target)
            {
                return 1;
            }
             if( (v[l] == v[mid]) && (v[r] == v[mid]) ) {++l; --r;}
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
            else{
                if(v[r]>=target and v[mid+1]<=target)
                {
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
                
            }
         
           
        }
        return 0;
    }
};