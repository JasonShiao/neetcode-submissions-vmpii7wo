class Node {
public:
    Node(int val, int key) {
        this->val = val;
        this->key = key;
        freq = 1;
        prev = nullptr;
        next = nullptr;
    }
    int val;
    int freq;
    int key;
    Node* prev;
    Node* next;
};

class LFUCache {
private:
    unordered_map<int, Node*> key_node_map;
    Node* list_head; // least frequent node
    Node* list_tail; // most frequent node
    int capacity = 0;
    int size = 0;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        // build a hash map point to the node
        // doubly linked list -> swap right until next freq > curr freq
        // Add a dummy node as head & tail for convenience
        list_head = new Node(-1, -1);
        list_head->freq = 0;
        list_tail = new Node(-1, -1);
        list_tail->freq = INT_MAX;
        // initialize links
        list_head->next = list_tail;
        list_tail->prev = list_head;
    }
    
    int get(int key) {
        if (key_node_map.find(key) == key_node_map.end()) {
            return -1;
        }

        auto curr_node = key_node_map[key];
        curr_node->freq += 1;
        while (curr_node->next->freq <= curr_node->freq) {
            // swap -> affect 6 links and 4 consecutive nodes
            auto left = curr_node->prev;
            auto right = curr_node->next->next;
            auto swapped_node = curr_node->next;

            left->next = swapped_node;
            swapped_node->prev = left;
            right->prev = curr_node;
            curr_node->next = right;
            curr_node->prev = swapped_node;
            swapped_node->next = curr_node;
        }
        return curr_node->val;
    }
    
    void put(int key, int value) {
        if (key_node_map.find(key) == key_node_map.end()) {
            // if exceed the capacity, remove the node after the dummy head
            // NOTICE: before inserting the new node!!!!
            if (size == capacity) {
                auto tmp = list_head->next;
                int deleted_key = tmp->key;
                tmp->next->prev = list_head;
                list_head->next = tmp->next;
                delete tmp;
                key_node_map.erase(deleted_key);

                size -= 1;
            }

            // create new node
            Node* new_node = new Node(value, key);
            key_node_map[key] = new_node;
            // insert after head
            list_head->next->prev = new_node;
            new_node->next = list_head->next;
            new_node->prev = list_head;
            list_head->next = new_node;

            size += 1; // increase size for new key
        } else {
            key_node_map[key]->val = value;
            key_node_map[key]->freq += 1;
        }
        // swap with latter node until freq > curr freq
        auto curr_node = key_node_map[key];
        while (curr_node->next->freq <= curr_node->freq) {
            // swap -> affect 6 links and 4 consecutive nodes
            auto left = curr_node->prev;
            auto right = curr_node->next->next;
            auto swapped_node = curr_node->next;

            left->next = swapped_node;
            swapped_node->prev = left;
            right->prev = curr_node;
            curr_node->next = right;
            curr_node->prev = swapped_node;
            swapped_node->next = curr_node;
        }


    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */