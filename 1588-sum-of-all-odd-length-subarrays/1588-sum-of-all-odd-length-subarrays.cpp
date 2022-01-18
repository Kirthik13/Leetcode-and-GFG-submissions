class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& v) {
        int n=v.size(),c{};
    for (int i = 0; i < n; i++)
    {
        int contribution = ceil(((i + 1) * (n - i)) / 2.0);
        c += contribution * v[i];
    }
        return c;
    }
};