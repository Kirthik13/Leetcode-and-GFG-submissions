#define all(x) x.begin(),x.end()
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& v) {
         // vector<vector<int>>v={{10,16},{2,8},{1,6},{7,12}};
    sort(all(v),[](auto &a,auto &b)
    {
        // if(a[0]==b[0])
        // {
            return a[1]<b[1];
        // }
        // return a[0]<b[0] ;
    }
    );
    // for(auto i:v)
    // {
    //     for(auto j:i)
    //     {
    //         cout<<j<<" ";
    //     }
    //     cout<<nx;
    // }
    // cout<<sum;

    // vector<vector<int>>v2;
   int cnt=1;
    int end=v[0][1];

    for(auto i:v)
    {
        if(i[0]<=end) continue;

        cnt++;
        end=i[1];
    }
        return cnt;
    }
};