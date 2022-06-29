class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& v) {
        // map<int,multiset<int>>m;
        // for(auto &i:v)
        // {
        //     m[i[1]].insert(i[0]);
        // }
                
//         for(auto &i:m[0])
//         {
//             tot.push_back({i,0});
//         }
//         int curr_size=tot.size();
//         int n=v.size();
        
//         for(auto &i:m)
//         {
//             cout<<i.first<<" ; ";
//             for(auto &j:i.second)
//             {
//                 cout<<j<<" ";
//             }
//             cout<<endl;
//         }
//         // while(tot.size()<n)
//         // {
//         //     for(auto &i:m)
//         //     {
//         //         if(i.first==0) continue;
//         //         int num=i.first;
//         //         for(auto &k:i.second)
//         //         {
//         //             int h=k;
//         //             int c{};
//         //             for(auto &j:tot)
//         //             {
//         //                 if(j[1]<=h) c++;
//         //             }
//         //             if(c==num)
//         //             {
//         //                 tot.push_back({h,num});
//         //                 break;
//         //             }
//         //         }
//         //     }
//         // }
        vector<vector<int>>res;
        sort(begin(v),end(v),[](auto p1,auto p2)
          { 
              return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]); 
          }
        );
         for (auto& p : v) 
            res.insert(res.begin() + p[1], p);
    // return res;
        return res;
    }
};