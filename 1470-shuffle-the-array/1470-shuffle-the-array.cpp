class Solution {
public:
    vector<int> shuffle(vector<int>& v, int n) {
       for(int i=n;i<v.size();i++)
       {
           v[i]=(v[i]*1024)+v[i-n];
       }
       int idx=0;
        for(int i=n;i<v.size();i++)
        {
            v[idx]=v[i]%1024;
            v[idx+1]=v[i]/1024;
            
            idx+=2;
        }
        return v;
    }
};