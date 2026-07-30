/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#define node ListNode
#define null NULL
class Solution {
public:
    bool hasCycle(ListNode *head) {
        node* fast = head;
        node* slow = head;
        while(fast!=null&&fast->next!=null){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) return true;
        }

        return false;
    }
};