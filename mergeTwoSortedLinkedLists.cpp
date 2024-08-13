#include <iostream>
#include <cstdlib>
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *head)
{
    ListNode *current = head;
    while (current != nullptr)
    {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode *tail = &dummy;

        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        if(list1 != nullptr){
            tail->next = list1;
        } else {
            tail->next = list2;
        }
    return dummy.next;
    }
};

int main(){
    ListNode* node31 = new ListNode(7);
    ListNode* node21 = new ListNode(5, node31);
    ListNode* node11 = new ListNode(3, node21);
    ListNode* head1 = new ListNode(1, node11);

    ListNode* node32 = new ListNode(6);
    ListNode* node22 = new ListNode(4, node32);
    ListNode* node12 = new ListNode(2, node22);
    ListNode* head2 = new ListNode(0, node12);

    Solution sol;
    
    std::cout << "\nSeparate Lists:\n";
    printList(head1);
    printList(head2);

    std::cout << "\n\nSolution:\n"; 
    ListNode *solution = sol.mergeTwoLists(head1, head2);
    printList(solution);

}
