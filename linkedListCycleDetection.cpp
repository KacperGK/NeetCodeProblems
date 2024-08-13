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

class Solution{
    public:
        bool hasCycle(ListNode *head){
            if(head == nullptr || head->next == nullptr) return false;

            ListNode *slow = head;
            ListNode *fast = head;


            while(fast && fast->next){
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast) return true;
            }
            return false;
        }
};

int main(){
    ListNode* node3 = new ListNode(3);
    ListNode* node2 = new ListNode(2, node3);
    ListNode* node1 = new ListNode(1, node2);
    ListNode* head = new ListNode(0, node1);
    
    node3->next = node1; //creation of cycle;

    Solution sol;
    bool result = sol.hasCycle(head);
    std::cout << "Output: " << result << std::endl;
}