class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& v) {
        sort(begin(v),end(v),[](auto &a,auto &b)
             {
                 if(a[0]<b[0])
                 {
                     return 1;
                 }
                 if(a[0]==b[0])
                 {
                     if(a[1]>b[1])
                     {
                         return 1;
                     }
                 }
                 return 0;
             });
        int c=0;
        int f=v[0][0],s=v[0][1];
        // for(auto i:v)
        // {
        //     cout<<i[0]<<" "<<i[1]<<endl;
        // }
        for(auto i=1;i<v.size();i++)
        {
            
              if(f<=v[i][0] and s>=v[i][1])
              {
               c++;
                  continue;
              }
                f=v[i][0];
                s=v[i][1];
            
        }
//         cout<<"f : "<<f<<" s : "<<s<<endl;
        return v.size()-c;
        
    }
};