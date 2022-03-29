class Solution {
public:
    int findDuplicate(vector<int>& v) {
//         int f=v[0],s=v[0];
//         do
//         {
//             s=v[s];
//             f=v[v[f]];
//         }while(s!=f);

//         f=v[0];
//         while(s!=f)
//         {
//             s=v[s];
//             f=v[f];
//         }
//         return s;
        
        
        int l=1,r=v.size()-1;
        while(l<r)
        {
            int mid=(l+r)/2;
            int c{};
            for(auto &i:v)
            {
                if(i<=mid) c++;
            }
            if(c>mid) r=mid;
            else{
                l=mid+1;
            }
        
        }
        return r;
    }
};