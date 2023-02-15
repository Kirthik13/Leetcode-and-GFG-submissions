class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int>ans;
        
        int rem=0;
        int i=num.size()-1;
        int sum=k;
        for(;i>=0;i--){
            sum = num[i]+sum;
            rem = sum % 10;
            ans.push_back(rem);
            sum/=10;
        }
        
        while(sum>0){ 
            ans.push_back(sum%10);
             sum/=10; 
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};