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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 and !list2)
            return NULL;
        if(!list1)
            return list2;
        if(!list2)
            return list1;
         ListNode* head = new ListNode();
         

         ListNode* curr = head;
         while(list1 and list2)
         {
                 ListNode* temp = new ListNode();
                 if(list1->val<=list2->val)
                 {
                     temp->val = list1->val;
                     curr->next = temp;
                     list1 = list1->next;
                     curr = curr->next;
                 }
                 else
                 {
                     temp->val = list2->val;
                     curr->next = temp;
                     list2 = list2->next;
                     curr = curr->next;
                 }
             
         }
         if(list1)
         {
             curr->next = list1;
         }
         else if(list2)
         {
             curr->next = list2;
         }
         return head->next;
    }
};