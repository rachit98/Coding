/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* prev = new ListNode();
        ListNode* curr = prev;
        int carry = 0;
        while(l1 and l2)
        {
            int sum = carry + l1->val + l2->val;
            if(sum>9)
            {
                carry = sum/10;
                sum = sum%10;
            }
            else
                carry = 0;
            ListNode* temp = new ListNode(sum);
            curr->next = temp;
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1)
        {
            int sum = carry + l1->val;
            if(sum>9)
            {
                carry = sum/10;
                sum = sum%10;
            }
            else
                carry = 0;
            ListNode* temp = new ListNode(sum);
            curr->next = temp;
            curr = curr->next;
            l1 = l1->next;
        }
        while(l2)
        {
            int sum = carry + l2->val;
            if(sum>9)
            {
                carry = sum/10;
                sum = sum%10;
            }
            else
                carry = 0;
            ListNode* temp = new ListNode(sum);
            curr->next = temp;
            curr = curr->next;
            l2 = l2->next;
        }
        if(carry)
        {
            ListNode* temp = new ListNode(carry);
            curr->next = temp;
            curr = curr->next;
        }
        return prev->next;
    }
};