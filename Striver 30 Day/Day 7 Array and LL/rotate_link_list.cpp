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
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        if(k==0)
            return head;
        if(!head or !head->next)
            return head;
        ListNode* temp = head;
        while(temp)
        {
            len++;
            temp = temp->next;
        }
        k = k%len;
        if(k==0)
            return head;
        
        int moves = len - k;
        ListNode* curr = head;
        for(int i=1;i<moves;i++)
        {
            curr = curr->next;
        }
        ListNode* newHead = curr->next;
        curr->next = NULL;
        curr = newHead;

        while(curr->next)
        {
            curr = curr->next;
        }
        curr->next = head;
        return newHead;
    }
};