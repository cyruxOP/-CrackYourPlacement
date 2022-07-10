class LFUCache {
public:
    struct Node{
        int key,val,cnt;
        Node* prev;
        Node* next;
        Node(int key, int val )
        {
            this->key=key;
            this->val=val;
            cnt=1;
            next=NULL;
            prev=NULL;
        }
    };
    struct list{
        int size;
        Node* head;
        Node* tail;
        list()
        {
            head=new Node(0,0);
            tail=new Node(0,0);
            head->next=tail;
            tail->prev=head;
            size=0;
        }
        void addn(Node *a)
        {
            Node* temp = head->next;
            head->next=a;
            a->next=temp;
            a->prev=head;
            temp->prev=a;
            size++;
        }
        void deln(Node *a)
        {
            Node *delpre = a->prev;
            Node *delnex = a->next;
            delpre->next=delnex;
            delnex->prev=delpre;
            size--;
        }
    };
    unordered_map<int,Node*> keyNode;
    unordered_map<int,list*> freqList;
    int minfreq,cursize,mxsize;
    LFUCache(int capacity) {
        mxsize=capacity;
        minfreq=0;
        cursize=0;
    }
    void upfqmap(Node *a)
    {
        freqList[a->cnt]->deln(a);
        if(a->cnt==minfreq && freqList[a->cnt]->size==0)
            minfreq++;
        list* nlist = new list();
        if(freqList.find(a->cnt+1)!=freqList.end())
            nlist = freqList[a->cnt+1];
        a->cnt+=1;
        nlist->addn(a);
        freqList[a->cnt]=nlist;
        
    }
    
    int get(int key) {
        if(keyNode.find(key)!=keyNode.end())
        {
            Node *nod = keyNode[key];
            int res = nod->val;
            upfqmap(nod);
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mxsize==0) return;
        if(keyNode.find(key)!=keyNode.end())
        {
            Node *node = keyNode[key];
            node->val = value;
            upfqmap(node);
            
        }else
        {
            if(cursize==mxsize)
            {
                list* nlist=freqList[minfreq];
                keyNode.erase(nlist->tail->prev->key);
                freqList[minfreq]->deln(nlist->tail->prev);
                cursize--;
            }
            cursize++;
            minfreq=1;
            list* nlist= new list();
            if(freqList.find(minfreq)!=freqList.end())
            {
                nlist=freqList[minfreq];
            }
            Node* node = new Node(key,value);
            nlist->addn(node);
            keyNode[key] = node;
            freqList[minfreq]=nlist;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */