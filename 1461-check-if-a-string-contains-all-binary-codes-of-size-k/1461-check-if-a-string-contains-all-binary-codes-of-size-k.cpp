class Solution {
public:
    bool fn(set<string>&st2,int &win,string t)
    {
        if(t.size()==win)
        {
            // st.insert(t);
            if(st2.find(t)==st2.end()) return 0;
            return 1;
        }
        // for(int i=0;i<win;i++)
        // {
            // t.push_back('0');
            if(!(fn(st2,win,t+'0'))) return 0;
            // if(t.size()>0)
            // {
            //     t.pop_back();
            // }
            
            // t.push_back('1');
             if(!(fn(st2,win,t+'1'))) return 0;
            // if(t.size()>0)
            // {
            //     t.pop_back();
            // }
        // }
        return 1;
    }
    bool hasAllCodes(string s, int k) {
        int n=s.size();
        if(s.size()<k) return 0;
        int win=k;
        string t;
        // set<string>st;
         set<string>st2;
        for(int i=0;i<=s.size()-win;i++)
        {
            string g=s.substr(i,win);
        
            st2.insert(g);
        }       
        if(fn(st2,win,t)) return 1;
      
        return 0;
    }
};