/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        if(!head)
            return false;
        if(slow->next)
            slow = slow->next;
        else
            return false;
        if(fast->next->next)
            fast = fast->next->next;
        else
            return false;
        while(slow->next and fast->next and fast->next->next)
        {
            if(slow==fast)
                return true;
            
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};