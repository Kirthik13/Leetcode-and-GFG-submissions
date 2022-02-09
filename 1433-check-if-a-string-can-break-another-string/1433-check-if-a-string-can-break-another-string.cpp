
class Solution {
public:
 
    bool checkIfCanBreak(string s1, string s2) {
        // long long int a=hash(s1);
        // long long int b=hash(s2);
        if(s1.size()==1)
        {
            if(s1[0]<=s2[0]) return 1;
            if(s1[0]>=s2[0]) return 1;
                return 0;
        }
        sort(begin(s1),end(s1));
        sort(begin(s2),end(s2));
    int f=1;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]<s2[i])
            {
                f=0;
                break;
            }
        }
        if(f) return 1;
        f=1;
        for(int i=0;i<s2.size();i++)
        {
            if(s1[i]>s2[i])
            {
                f=0;
                break;
            }
        }
        if(f) return 1;
        return 0;
    }
};