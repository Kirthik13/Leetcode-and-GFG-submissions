class Solution {
public:
    int largestPerimeter(vector<int>& v) {
        sort(begin(v),end(v));
        
        for(int i=v.size()-1;i>=2;i--)
        {
            if(v[i]<v[i-1]+v[i-2]) return v[i]+v[i-1]+v[i-2];
        }
        return 0;
    }
};