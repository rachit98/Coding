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
    bool isPalindrome(ListNode* head) {
        if(!head or !head->next)
            return true;
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* mid = head;
        while(fast->next and fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        mid = slow->next;
        
        ListNode* prev = NULL;
        ListNode* curr = mid;
        
        while(curr)
        {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        ListNode* newhead = prev;
        ListNode* oldhead = head;
        while(newhead and oldhead)
        {
            if(newhead->val !=oldhead->val)
                return false;
            
            newhead = newhead->next;
            oldhead = oldhead->next;
        }
        return true;
    }
};