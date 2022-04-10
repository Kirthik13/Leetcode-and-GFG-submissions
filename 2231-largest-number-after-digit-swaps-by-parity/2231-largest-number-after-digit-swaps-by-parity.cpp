class Solution {
public:
    int largestInteger(int num) {
        string s=to_string(num);
       priority_queue<int>odd,even;
        for(auto i=0;i<s.size();i++)
        {
            int g=int(s[i])-48;
            if(g%2==0)
            {
                even.push(g);
            }
            else{
                odd.push(g);
  
            }
        }
        int ans{};
        for(int i=0;i<s.size();i++)
        {
             int g=int(s[i])-48;
            if(g%2==0)
            {
                // even.push(g)
                ans=ans*10+even.top();
                even.pop();
            }
            else{
                // odd.push(g);
                 ans=ans*10+odd.top();
                odd.pop();
  
            }
        }
        return ans;
    }
};