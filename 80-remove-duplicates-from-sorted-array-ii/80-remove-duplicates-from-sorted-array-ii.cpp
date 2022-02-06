class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        map<int,int>m;
        int c{};
        for(auto &i:v)
            
        {
            m[i]++;
        }
        int j{};
        for(auto &i:m)
        {
            if(i.second>=2)
            {
                int n=2;
                while(n--)
                {
                    v[j++]=i.first;
                }
                c+=2;
               
            }
            else{
                c+=i.second;
                v[j++]=i.first;
            }
            // j++;
        }
        
        return c;
    }
};