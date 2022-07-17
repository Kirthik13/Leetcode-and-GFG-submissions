class Solution {
public:

 
    int minOperations(vector<int>& v, vector<int>& numsd) {
        int g=numsd[0];
        for(auto i=1;i<numsd.size();i++)
        {
            g=__gcd(g,numsd[i]);
        }
        sort(begin(v),end(v));
        for(int i=0;i<v.size() and v[i]<=g;i++)
        {
            if(g%v[i]==0) return i;
        }
     
        return -1;
    }
};