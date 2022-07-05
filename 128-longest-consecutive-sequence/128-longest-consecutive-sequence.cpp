class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        if(v.size()<=1) return v.size();
        
        map<int,int>m;
        for(auto &i:v)
        {
            m[i]++;
        }
        
        int prev=(m.begin()->first);
        int curr=1;
        int ans=0;
        auto i=m.begin();
        i++;
        for(;i!=m.end();i++)
        {
            int el=i->first;
            if(prev+1==el)
            {
                curr++;
            }
            else{
                ans=max(ans,curr);
                curr=1;
            }
            prev=el;

        }
        ans=max(ans,curr);
        return ans;
            
    }
};