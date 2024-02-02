/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        
        Node* temp = head;
        while(temp)
        {
            Node* duplicate = new Node(temp->val);
            // duplicate->val = temp->val;
            duplicate->next = temp->next;
            temp->next = duplicate;
            temp = temp->next->next;
        }

        temp = head;
        while(temp)
        {
            // Node* duplicate = temp->next;
            if(temp->random)
                temp->next->random = temp->random->next;
            
            temp = temp->next->next;
        }
        Node* dummy = new Node(0);
        temp = dummy;
        Node* itr = head;
        Node* fast;
        while(itr) 
        {
            fast = itr->next->next;
            temp->next = itr->next;
            itr->next = fast;
            temp = temp->next;
            itr = fast;
        }
        return dummy->next;
    }
};