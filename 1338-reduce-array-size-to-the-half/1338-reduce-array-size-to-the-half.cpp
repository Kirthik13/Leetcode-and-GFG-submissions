class Solution {
public:
    int minSetSize(vector<int>& v) {
        int n=v.size();
        map<int,int>m1;
          // map<int,int,greater<int>>m2;
        multiset<int,greater<int>>m2;
        for(auto &i:v) m1[i]++;
        for(auto &i:m1) m2.insert(i.second);
        
        int sum{},ans{};
        
        // for(auto &i:m2) cout<<i.first<<endl;
        
        for(auto &i:m2)
        {
            sum+=i;
                ans++;
            
            if(sum*2>=n)
            {
                return ans;
            }
            
            
        }
        return -1;
        
    }
};