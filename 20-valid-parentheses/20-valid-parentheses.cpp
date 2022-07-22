class Solution {
public:
    bool isValid(string s) {
        vector<char>v;
        for(auto &i:s)
        {
            if(v.empty())
            {
                v.push_back(i);
                continue;
            }
            if(i=='(' or i=='[' or i=='{') v.push_back(i);
            else{
                if(v.back()=='(' and i==')') v.pop_back();
                else if(v.back()=='[' and i==']') v.pop_back();
                else if(v.back()=='{' and i=='}') v.pop_back();
                else return 0;
                
            }
            
        }
        return v.empty();
    }
};