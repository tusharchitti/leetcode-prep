class Node
{
    public:
    int value;
    int key;
    Node *next;
    Node * prev;
    Node(int key, int value) {
        this->key= key;
        this->value= value;
        next= NULL;
        prev= NULL;
    }
};

class LRUCache {
public:
    unordered_map<int, Node*> mp;
     Node * head =NULL;
     Node * last = NULL;
    int m_size = 0;  
    int size = 0;

    LRUCache(int capacity) {
        m_size = capacity;
    } 
    
    void delAndMoveToLast(Node *tmp){
        if(tmp->prev == NULL) 
        {
            head = tmp->next;
            head->prev = NULL;
        }else{
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
        }
        last->next= tmp;
        tmp->prev= last;
        tmp->next= NULL;
        last =tmp;
    }

    int get(int key) {
         if(mp.find(key) == mp.end()) {
            return -1;
         }
           Node * tmp = mp[key];
            if(last!=tmp) {
                delAndMoveToLast(tmp);
            }
          
         return mp[key]->value;
    }

    void put(int key, int value) {
        if(mp.find(key) == mp.end()) {
            Node * tmp = new Node(key, value);
            size++;
            mp[key]= tmp;
            if(head  == NULL) {
                 head = tmp;
                 last = tmp;
            }
            else
            {
                 last->next=tmp;
                 tmp->prev = last;
                 last = tmp;
            }

            if(size>m_size) {
                   Node * tmp1 = head;
                   mp.erase(head->key);
                   head->next->prev =NULL;
                   tmp1 = NULL;
                   head = head->next; 
               size--;
            }
        }else {
            mp[key]->value = value;
             Node * tmp = mp[key];
            if(last!=tmp) {
               delAndMoveToLast(tmp);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */