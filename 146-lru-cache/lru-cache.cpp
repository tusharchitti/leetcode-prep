class LRUCache {
public:
    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
    };

    unordered_map<int, Node*> mp;
    int capacity;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = nullptr;
        tail = nullptr;
    }

    void moveToHead(Node* node) {
        if (node == head) return;

        // Remove node from its current position
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;

        // If the node is the tail, update the tail pointer
        if (node == tail) tail = node->prev;

        // Move node to the head
        node->next = head;
        node->prev = nullptr;
        if (head) head->prev = node;
        head = node;

        // Update tail if the list was empty
        if (!tail) tail = head;
    }

    void evict() {
        if (!tail) return;

        // Remove the tail node
        mp.erase(tail->key);
        Node* prevTail = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr; // List is now empty

        delete prevTail;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        Node* node = mp[key];
        moveToHead(node);
        return node->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            // Update the value of the existing node and move it to the head
            Node* node = mp[key];
            node->val = value;
            moveToHead(node);
        } else {
            if (mp.size() >= capacity) {
                // Evict the least recently used node
                evict();
            }

            // Add the new node
            Node* newNode = new Node(key, value);
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            if (!tail) tail = newNode;

            mp[key] = newNode;
        }
    }
};
