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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int flag1 = 0, flag2 = 0;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1 and temp2)
        {
            if(temp1==temp2)
                return temp1;
            if(!temp1->next and flag1==0)
            {
                flag1 = 1;
                temp1 = headB;            
            }
            else if(temp1->next)
                temp1 = temp1->next;
            else
                return NULL;
            
            if(!temp2->next and flag2==0)
            {
                flag2 = 1;
                temp2 = headA;            
            }
            else if(temp2->next)
                temp2 = temp2->next;
            else
                return NULL;   
            
        }
        return NULL;
        
    }
};