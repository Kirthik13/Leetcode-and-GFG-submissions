class MyCalendar {
public:
    set<pair<int,int>>st;
    bool isvalid(pair<int,int>i,int st,int en)
    {
        return (st>=i.second and en>i.second) or (st<i.first and en<=i.first);
    }
    MyCalendar() {
        
    }
    
    bool book(int s, int e) {
        auto next=st.lower_bound({s,e});
      
        if (next != st.end() && next->first < e) return false; 
        if (next != st.begin() && s < (--next)->second) return false; 
        st.insert({s,e});
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */