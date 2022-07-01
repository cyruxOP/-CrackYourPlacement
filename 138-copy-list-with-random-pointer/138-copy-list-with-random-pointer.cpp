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
        Node* front=head;
        Node* iter =head;
        while(iter)
        {
            front=iter->next;
            Node *copy = new Node(iter->val);
            iter->next=copy;
            copy->next=front;
            iter=front;
        }
        iter=head;
        front=head;
        while(iter)
        {
            if(iter->random)
            iter->next->random=iter->random->next;
            iter=iter->next->next;
        }
        iter=head;
        Node *dum = new Node(0);
        Node *tmp=dum;
        while(iter)
        {
            front=iter->next->next;
            tmp->next=iter->next;
            iter->next=front;
            tmp=tmp->next;
            iter=front;
        }
        return dum->next;
    
        
    }
};