class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int j=0;
        for(auto &i:v)
        {
            if(j<2 or i>v[j-2])
            {
                v[j++]=i;
            }
        }
        return j;
    //     int i = 0;
    // for (int n : nums)
    //     if (i < 2 || n > nums[i-2])
    //         nums[i++] = n;
    // return i;
    }
};