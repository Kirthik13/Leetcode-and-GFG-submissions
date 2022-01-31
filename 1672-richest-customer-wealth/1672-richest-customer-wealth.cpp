class Solution {
public:
    int maximumWealth(vector<vector<int>>& v) {
     // int ans=INT_MIN;
     //    for(auto &i:v)
     //    {
     //        int c{};
     //        for(auto &j:i)
     //        {
     //            c+=j;
     //        }
     //        ans=max(ans,c);
     //    }
     //    return ans;
        return accumulate(cbegin(v),cend(v),0,[](auto& sum,const auto &money)
                          {
                              // cout<<"sum : "<<sum<<endl;
                              return max(sum,reduce(cbegin(money),cend(money),0));
                          });
    }
};