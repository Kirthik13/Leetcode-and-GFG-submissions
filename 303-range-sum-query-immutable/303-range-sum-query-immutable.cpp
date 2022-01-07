class NumArray {
public:
    vector<int>ans;
    NumArray(vector<int>& v) {
        ans.push_back(v[0]);
        for(int i=1;i<v.size();i++)
        {
            int k=ans[i-1]+v[i];
            ans.push_back(k);
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0)
        {
            return ans[right];
        }
        return ans[right]-ans[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */