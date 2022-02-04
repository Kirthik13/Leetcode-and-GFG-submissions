class Solution {
public:
    int findMaxLength(vector<int>& v) {
        if(v.size()==1)
        {
            return 0;
        }
        int c{};
        unordered_map<int,int>m;
        m[0]=0;
        int sum{};
        for(int i=0;i<v.size();i++)
        {
            
           sum+=v[i]?1:-1;
           // if(m.find(-1)!=m.end())
           // {
           //     cout<<"ASd"<<endl;
           // }
             if(m.find(sum)!=m.end())
            {
                 if(sum==0)
                 {
                     c=i+1;
                 }
                 else{
                // cout<<sum<<" "<<m[sum]<<" a"<<endl;
                c=max(i-m[sum],c);
                 }
            }
            else{
            // cout<<sum<<" "<<m[sum]<<" b"<<endl;

            m[sum]=i;
            }
        }
        return c;
    }
};