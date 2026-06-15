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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* real=head;
        ListNode* temp=head;
        if(head->next==NULL)
        return head->next;
    
        while(temp->next && temp->next->next)
        {
            temp=temp->next->next;
            prev=real;
            real=real->next;
        }
        if(temp->next){
              prev=real;
            real=real->next;
        }

        prev->next=real->next;
       
        return head;

    }
};