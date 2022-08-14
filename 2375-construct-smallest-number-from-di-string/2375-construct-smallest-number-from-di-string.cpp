class Solution {
public:
    string smallestNumber(string pat) {
        string stack,res;
        
        for(int i=0;i<=pat.size();i++)
        {
            char ch=char(i+1)+'0';
                        stack.push_back(ch);

            if(i==pat.size() or pat[i]=='I')
            {
                while(!stack.empty())
                {
                    res.push_back(stack.back());
                    stack.pop_back();
                }
            }
            
        }
        return res;
    }
};