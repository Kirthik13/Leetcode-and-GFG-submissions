class Solution {
public:
    string getPermutation(int n, int k) 
    {
        vector<int>num;
        int fact=1;
        for(int i=1;i<n;i++)
        {
            fact*=i;
            num.emplace_back(i);
        }
        
        num.emplace_back(n);
        string ans;
        --k;
        while(true)
        {
            char ch=char(num[k/fact])+48;
            ans.push_back(ch);
            num.erase(num.begin()+(k/fact));
            
            if(num.size()==0) break;
            
            k=k%fact;
            fact=fact/num.size();
        }
        
        return ans;
        
        
    }
};