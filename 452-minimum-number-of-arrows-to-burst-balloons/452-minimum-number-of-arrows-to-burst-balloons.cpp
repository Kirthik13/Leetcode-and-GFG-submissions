#define all(x) x.begin(),x.end()
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& v) {
         
    sort(all(v),[](auto &a,auto &b)
    {
        // if(a[0]==b[0])
        // {
            return a[1]<b[1];
        // }
        // return a[0]<b[0] ;
    }
    );
        // sort(all(v));

   int cnt=1;
    int end=v[0][1],st=v[0][0];

 for(auto i:v)
 {
     if(i[0]<=end)
     {
         continue;
     }
     else{
         cnt++;
         end=i[1];
     }
 }
//         for(auto i:v)
//         {
//             if(i[0]<=end)
//             {
//                 end=min(i[1],end);
//             }
//             else{
//                 cnt++;
//                 end=i[1];
//             }
            
//         }
        return cnt;
    }
};