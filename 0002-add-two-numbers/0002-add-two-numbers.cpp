class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = nullptr;
        ListNode* tail = nullptr; 
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr) {
            int x = (l1 ? l1->val : 0);
            int y = (l2 ? l2->val : 0);
            int sum = x + y + carry;
            carry = sum / 10;
            sum = sum % 10;

            ListNode* newnode = new ListNode(sum);

            if (res == nullptr) {
                res = newnode;
                tail = newnode;
            } else {
                tail->next = newnode;
                tail = tail->next;
            }

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        if (carry > 0) {
            tail->next = new ListNode(carry);
        }

        return res;
    }
};
