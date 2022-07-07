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
class cmp{
    public:
    bool operator()(ListNode*a , ListNode*b)
    {
        return a->val > b->val;
    }
};
class Solution {
public:

    ListNode* mergeKLists(vector<ListNode*>& v) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        for(int i=0;i<v.size();i++)
        {
            if(v[i]!=NULL)
                pq.push(v[i]);  
        }
        while(pq.size())
        {
            ListNode* temp= pq.top();
            tail->next=temp;
            tail=temp;
            pq.pop();
            if(temp->next) pq.push(temp->next);
            
        }
        return dummy->next;
    }
};