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
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* entry = head;
        
        while(slow->next and fast->next and fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast)
            {
                while(entry!=slow)
                {
                    entry = entry->next;
                    slow = slow->next;
                }
                return slow;
            }

        }
        return NULL;
    }
};