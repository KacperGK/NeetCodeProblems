#include <iostream>
#include <cstdlib>
#include <vector>


struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *current = head;

        while(current != nullptr){
            ListNode *nextTemp = current->next;
            current->next = prev;
            prev = current;
            current = nextTemp;
        }
        return prev;
    }

};

    void printList(ListNode* head){
        ListNode* current = head;
        while(current != nullptr){
            std::cout << current->val << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

int main(){
    ListNode* node3 = new ListNode(0);
    ListNode* node2 = new ListNode(1, node3);
    ListNode* node1 = new ListNode(2, node2);
    ListNode* head = new ListNode(3
    , node1);

    // Print the original list
    std::cout << "Original list: ";
    printList(head);

    // Reverse the list
    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);

    // Print the reversed list
    std::cout << "Reversed list: ";
    printList(reversedHead);

    // Clean up memory (optional but good practice)
    delete node3;
    delete node2;
    delete node1;
    delete head;

    return 0;
}