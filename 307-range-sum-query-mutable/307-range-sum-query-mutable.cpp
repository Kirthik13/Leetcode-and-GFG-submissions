class NumArray {
public:
     vector<int> bit;
     vector<int> arr;
    
    void update1(int i, int x)
    {
        int n=bit.size();
        for(; i < n; i += (i&-i))
            bit[i] += x;
    }

    int sum(int i){
        long long int ans = 0;
        for(; i > 0; i -= (i&-i))
            ans += bit[i];
        return ans;
    }
    NumArray(vector<int>& v) {
              bit = vector<int>(v.size()+1,0);
              arr = v;

        for(int i=0;i<v.size();i++)
        {
            update1(i+1,v[i]);
        }
    }
    
    void update(int index, int val) {
         int diff = val-arr[index];
        update1(index+1,diff);
                arr[index]=val;

    }
    
    int sumRange(int left, int right) {
        return sum(right+1)-sum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */