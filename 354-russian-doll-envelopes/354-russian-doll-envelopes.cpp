class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& v) {
        sort(begin(v),end(v),[](auto a,auto b)
             {
                if(a[0]==b[0]) return a[1]>b[1];
                 return a[0]<b[0];
             });
        
        vector<int>lis;
        for(int i=0;i<v.size();i++)
        {
            int ele=v[i][1];
            int idx=lower_bound(begin(lis),end(lis),ele)-begin(lis);
            if(idx>=lis.size()) lis.push_back(ele);
            else{
                lis[idx]=ele;
            }
        }
        return lis.size();
    }
};