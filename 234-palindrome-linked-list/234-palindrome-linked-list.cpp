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
    ListNode *rev(ListNode *node)
    {
        ListNode *pre =NULL;
        ListNode *curr=node;
        ListNode *nex=NULL;
        while(curr!=NULL)
        {
            nex = curr->next;
            curr->next =pre;
            pre=curr;
            curr=nex;
            
        }
        return pre;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        slow->next = rev(slow->next);
        slow = slow->next;
        while(slow!=NULL)
        {
            if(slow->val == head->val)
            {
                slow=slow->next;
                head=head->next;
            }
            else return 0;
        }
        return 1;
    }
};