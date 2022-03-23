class Solution {
public:
    int brokenCalc(int sv, int target) {
        int ans{};
        while(sv<target)
        {
            ans++;
            if(target%2) ++target;
            else{
                target/=2;
            }
            
        }
        return sv-target+ans;
    }
};