class LRUCache {
public:
    list<int>dq;
    map<int,pair<int,list<int>::iterator>>m;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end())
        {
            dq.erase(m[key].second);
            dq.push_front(key);
            m[key].second=dq.begin();
            return m[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if( m.find(key)==m.end())
        {
            if(m.size()==cap)
            {
                m.erase(dq.back());
                dq.pop_back();
            }
            dq.push_front(key);
            m[key]={value,dq.begin()};
        
        }
        else{
            dq.erase(m[key].second);
            dq.push_front(key);
            m[key]={value,dq.begin()};
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */