class LRUCache {
public:
    class node
    {
        
        public:
            node*  prev;
            node* next;
            int key,value;

            node(int k,int v)
            {
                this->key=k;
                this->value=v;
            }
        
    };
    
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    
    unordered_map<int,node*>m;
    int cap;
    LRUCache(int capacity) {
        this->cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    
    void addnode(node* a)
    {
        node* tem=head->next;
        a->next=tem;
        tem->prev=a;
        head->next=a;
        
        a->prev=head;
    }
    
    void deletenode(node* h)
    {
        node* nprev=h->prev;
        node* nnext=h->next;
        
        nprev->next=nnext;
        nnext->prev=nprev;
    }
        
    
    
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
       
        node* t=m[key];
        int res=t->value;
         m.erase(key);
        deletenode(t);
        addnode(t);
        m[key]=head->next;
            
        return res;
        
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
             node* t=m[key];
            m.erase(key);
            deletenode(t);
        }
        if(m.size()==cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        m[key]=head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
