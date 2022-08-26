class Solution {
public:
    string sorted(int n)
    {
       string res=to_string(n);
        
        sort(begin(res),end(res));
        return res;
    }
    bool reorderedPowerOf2(int n) {
        string res=sorted(n);
        
        for(int i=0;i<32;i++)
        {
            if(res==sorted((1<<i))) return 1;
        }
        return 0;
        
    }
};