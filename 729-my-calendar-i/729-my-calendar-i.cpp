class MyCalendar {
public:
    set<pair<int,int>>st;
    bool isvalid(pair<int,int>i,int st,int en)
    {
        return (st>=i.second and en>i.second) or (st<i.first and en<=i.first);
    }
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto &i:st)
        {
            if(!isvalid(i,start,end))
            {
               return false;
            }
        }
        st.insert({start,end});
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */