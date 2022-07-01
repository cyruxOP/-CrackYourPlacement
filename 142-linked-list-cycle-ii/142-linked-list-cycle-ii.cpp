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
        ListNode *fast=head;
        ListNode *slow=head;
        if(head==NULL) return NULL;
        if(head->next==NULL) return NULL;
        do{
            fast=fast->next;
            if(fast==NULL || fast->next==NULL)
                return NULL;
            fast=fast->next;
            slow=slow->next;
        }while(fast!=slow);
        
        fast = head;
        while(fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};