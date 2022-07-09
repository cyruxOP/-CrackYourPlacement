class LRUCache {
public:
    class Node{
        public:
        int key,val;
        Node *prev , *next;
        Node(int key,int val)
        {
            this->key=key;
            this->val=val;
            prev=NULL;
            next=NULL;
        }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int size;
    unordered_map<int,Node*> mp;
    
    LRUCache(int cap) {
        size=cap;
        head->next=tail;
        tail->prev=head;
    }
    void delnode(Node* a)
    {
        Node *delpre=a->prev;
        Node *delnex=a->next;
        delpre->next=delnex;
        delnex->prev=delpre;
    }
    void addnode(Node* b)
    {
        Node* temp=head->next;
        head->next=b;
        b->next=temp;
        b->prev=head;
        temp->prev=b;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            Node* resn=mp[key];
            int res=resn->val;
            delnode(resn);
            addnode(resn);
            mp[key]=head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            Node *curn = mp[key];
            delnode(curn);
            if(value==curn->val)
            addnode(curn);
            else
            addnode(new Node(key,value));
            mp[key]=head->next;
        }
        else if(mp.size()==size)
        {
            Node* curn = tail->prev;
            mp.erase(curn->key);
            delnode(curn);
            addnode(new Node(key,value));
            mp[key]=head->next;      
        }
        else{
            addnode(new Node(key,value));
            mp[key]=head->next;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */