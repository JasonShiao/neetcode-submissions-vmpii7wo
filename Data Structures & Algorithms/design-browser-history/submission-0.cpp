class ListNode {
public:
    string url;
    ListNode* prev;
    ListNode* next;

    ListNode(string url, ListNode* prev) {
        this->prev = prev;
        next = nullptr;
        this->url = url;
    }
};

class BrowserHistory {
private:
    ListNode* head = nullptr;
    ListNode* cur = nullptr;
public:
    BrowserHistory(string homepage) {
        head = new ListNode(homepage, nullptr);
        cur = head;
    }
    
    void visit(string url) {
        cur->next = new ListNode(url, cur);
        cur = cur->next;
    }
    
    string back(int steps) {
        while (cur->prev != nullptr && steps > 0) {
            cur = cur->prev;
            steps -= 1;
        }

        return cur->url;
    }
    
    string forward(int steps) {
        while (cur->next != nullptr && steps > 0) {
            cur = cur->next;
            steps -= 1;
        }

        return cur->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */