class Solution {
public:
    vector<int>freqint(int n)
    {
        vector<int>ans(10);
        while(n!=0)
        {
            ans[n%10]++;
            n/=10;
            
        }
        return ans;
    }
        
    bool reorderedPowerOf2(int n) {
       vector<int>freq=freqint(n);
        for(int i=0;i<31;i++)
        {
            vector<int>g=freqint((int)pow(2,i));
            if(freq==g)
            {
                return 1;
            }
        }
        return 0;
    }
};