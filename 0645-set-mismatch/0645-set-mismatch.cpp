class Solution {
public:
    vector<int> findErrorNums(vector<int>& v)
    {
        vector<int>res(2);
        
        int mis{},dup{};
     
        map<int,int>m;
        
        for(auto &i:v)
        {
            m[i]++;
        }
        
        for(auto &i:m)
        {
            if(i.second==2)
            {
                res[0]=i.first;
                break;
            }
        }
        
        for(int i=1;i<=v.size();i++)
        {
            if(m[i]==0)
            {
                res[1]=i;
                break;
            }
        }
       
        return res;
    }
};