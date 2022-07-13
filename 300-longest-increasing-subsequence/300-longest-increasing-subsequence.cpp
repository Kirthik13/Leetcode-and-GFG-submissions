class Solution {
public:
    int lengthOfLIS(vector<int>& v) {
        
        vector<int>temp;
        temp.push_back(v[0]);
        for(int i=1;i<v.size();i++)
        {
            if(v[i]>temp.back())
            {
                temp.push_back(v[i]);
            }
            else{
                auto idx=lower_bound(begin(temp),end(temp),v[i])-begin(temp);
                
                temp[idx]=v[i];
            }
        }
        return temp.size();
    }
};