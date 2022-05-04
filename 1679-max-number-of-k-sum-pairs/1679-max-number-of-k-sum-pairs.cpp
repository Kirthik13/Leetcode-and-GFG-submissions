class Solution {
public:
    int maxOperations(vector<int>& v, int k) {
        unordered_map<int,int>m;
        for(auto &i:v)
        {
            m[i]++;
        }
        int c{};
        for(auto i=0;i<v.size();i++)
        {
            int ele=v[i];
            int new_ele=k-ele;
            if(m.find(new_ele)!=m.end() and m[new_ele]>0 and m[ele]>0 )
            {
                if(ele==new_ele and m[ele]>1)
                {
                    m[ele]-=2;
                    if(m[new_ele]==0) m.erase(new_ele);

                    c++;
                }
                else if(ele!=new_ele){
                    m[new_ele]--;
                    m[ele]--;
                    if(m[new_ele]==0) m.erase(new_ele);
                    if(m[ele]==0) m.erase(ele);
                    c++;
                }
                
            }
        }
        return c;
    }
};