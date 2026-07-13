/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        ImmutableListNode* last_node = nullptr;
        ImmutableListNode* cur = head;
        while (true) {
            if (cur->getNext() == last_node) {
                // print and update last_node ptr
                cur->printValue();
                last_node = cur;
                cur = head; // restart from head
                
                // terminate condition
                if (last_node == head) {
                    break;
                }
            } else {
                cur = cur->getNext();
            }
            
        }
    }
};
