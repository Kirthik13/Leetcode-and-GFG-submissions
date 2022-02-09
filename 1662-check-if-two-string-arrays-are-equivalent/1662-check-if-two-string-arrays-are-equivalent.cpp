class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& s1, vector<string>& s2) {
        int i=0,j=0,a1=0,b1=0;
        while(i<s1.size() and j<s2.size())
        {
            string k=s1[i],t=s2[j];
            
            if(k[a1]!=t[b1]) return 0;
            
            if(a1+1==k.size())
            {
                a1=0;
                i++;
            }
            else{
                a1++;
            }
            if(b1+1==t.size())
            {
                b1=0;
                j++;
            }
            else{
                b1++;
            }
                
        }
        return i==s1.size() and j==s2.size();
        // return t1==t2;

    }
};