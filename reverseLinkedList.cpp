#include <iostream>
#include <cstdlib>
#include <vector>

/*
Linked list is a data structure that consist of sequence of elements called nodes. Each node contain data(value) and pointer(or reference) to next node
first node is head, last node points to nullptr(end of a list)

types are: single (each points to next), double (each points to next and previous), circular (last node points again to head instead of nullptr)

+: dynamic size and efficient insertion/deletion
-: memory overhead(extra memory for a pointer in last node), squential access, much more complex than arrays


*/
struct ListNode { // making a structure
      int val; // value stored in a node
      ListNode *next; // pointer to the next node in a list

      //Constructors
      ListNode() : val(0), next(nullptr) {} // initializes a node with value 0 and sets next to null;
      ListNode(int x) : val(x), next(nullptr) {} // initializes a node with given value and sets next to null ptr;
      ListNode(int x, ListNode *next) : val(x), next(next) {} // initializes a node with value x and pointer to the next node
 };

class Solution { // class that contains a method to reverse linked list
public:
    ListNode* reverseList(ListNode* head) { // method that reverses a list, "ListNode* reverseList" -> function returns a pointer to LisNode(new head which is a pointer to first node)
                                            // "(ListNode* head)" -> funcion takes a pointer to a ListNode object as a paramtere, pointer represent the head (first node) of the original list
        ListNode *prev = nullptr; // initializing a pointer, which at last will be a new head of reversed list
        ListNode *current = head; // pointer to original head from list

        std::cout << "\n\nInitial state inside loop: " <<  std::endl;
        std::cout << "prev: nullptr, current: " << (current ? std::to_string(current->val) : "nullptr") << "\n";

        while(current != nullptr){ // look trought loop until current becomes null
            ListNode *nextTemp = current->next; // Store the next node in the sequence in temporary pointer, current is a pointer to a ListNode object(structure) so when we are dealing
            // with pointer to strucutre or class we can use arrow operator to acces membbers of the object. Each node is processed by iterating through "current pointer"

            std::cout << "\n\nBefore changing pointers: \n";
            std::cout << "current: " << current->val << " | current->next: " << (nextTemp ? std::to_string(nextTemp->val) : "nullptr") << std::endl;
            std::cout << "prev: " << (prev ? std::to_string(prev->val) : "nullptr") << std::endl;

            current->next = prev; // reverses the current nodes next pointer to point to previous node
            prev = current; // moves prev to current
            current = nextTemp; // current becomes next

            std::cout << "\nAfter changing pointers \n";
            std::cout << "prev now points to: " << prev->val << std::endl;
            std::cout << "current now points to: " << (current ? std::to_string(current->val) : "nullptr") << std::endl;
        }

        std::cout << "Final state: \n";
        std::cout << "prev(new head): " << (prev ? std::to_string(prev->val) : nullptr);
        return prev; // at the end prev will be new head of the reversed list
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
    ListNode* node3 = new ListNode(3);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);
    ListNode* head = new ListNode(0, node1);

    // Print the original list
    std::cout << "Original list: ";
    printList(head);

    // Reverse the list
    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);

    // Print the reversed list
    std::cout << "\n\nReversed list: ";
    printList(reversedHead);

    // Clean up memory (optional but good practice)
    delete node3;
    delete node2;
    delete node1;
    delete head;

    return 0;
}