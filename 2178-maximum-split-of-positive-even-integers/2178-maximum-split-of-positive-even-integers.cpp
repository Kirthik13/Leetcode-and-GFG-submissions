class Solution {
public:
    vector<long long> maximumEvenSplit(long long n) {
        if(n&1) return {};
        vector<long long>v;
        long long i=2;
        while(n/2>i)
        {
            v.emplace_back(i);
            
            n-=i;
            i+=2;
        }
        v.emplace_back(n);
        return v;
    }
};