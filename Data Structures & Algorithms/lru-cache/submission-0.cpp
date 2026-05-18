class Node {
public:
    Node (int key, int val) {
        this->key = key;
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }

    int key;
    int val;
    Node* next;
    Node* prev;
};

class LRUCache {
private:
    int capacity_;
    int cnt_;
    unordered_map<int, Node*> lookup;
    Node* head; // point to dummy head
    Node* tail; // point to dummy tail
    Node dummy_head{-1, 0}; // before MRU
    Node dummy_tail{-2, 0}; // after LRU
public:
    LRUCache(int capacity) {
        // Hint: hash map with value being the node addr
        //       maintain doubly linked list for LRU and MRU 
        capacity_ = capacity;
        cnt_ = 0;

        // use dummy node(s) for cleaner code
        head = &dummy_head;
        tail = &dummy_tail;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (lookup.find(key) == lookup.end()) {
            return -1;
        } else {
            Node* tmp = lookup[key];

            // move the node to the MRU
            // connect the prev and next (skip the tmp) (2 links changed)
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            // connect tmp to its new neighbors (4 links changed)
            tmp->next = head->next;
            head->next->prev = tmp;
            head->next = tmp;
            tmp->prev = head;

            return tmp->val;
        }
    }
    
    void put(int key, int value) {
        if (lookup.find(key) == lookup.end()) {
            // not hit: add
            Node* new_node_ptr = new Node(key, value);
            // add to hash
            lookup[key] = new_node_ptr;

            if (cnt_ == capacity_) {
                // remove the LRU from both hash and linked list
                Node* lru = tail->prev;
                lookup.erase(lru->key); // remove from hash
                // detach from linked list
                lru->prev->next = lru->next;
                lru->next->prev = lru->prev;
                // update cnt
                cnt_ -= 1;
            }

            // append to head of linked list 
            new_node_ptr->next = head->next;
            head->next->prev = new_node_ptr;
            head->next = new_node_ptr;
            new_node_ptr->prev = head;
            // inc the counter
            cnt_ += 1;

        } else {
            // hit -> update
            Node* tmp = lookup[key];
            tmp->val = value;

            // update linked list
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            // connect tmp to its new neighbors (4 links changed)
            tmp->next = head->next;
            head->next->prev = tmp;
            head->next = tmp;
            tmp->prev = head;

        }
    }
};
