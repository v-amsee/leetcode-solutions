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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *tmp=head;
        int count=0;
        
        while(tmp!=nullptr)
        {
            count++;
            tmp=tmp->next;
        }    
        int pos=count-n +1,counter=0;
        ListNode * curr =head;
        if(pos==1)
            return head->next;
        while(curr!=nullptr)
        {  
            counter++;
            if (counter==pos-1)
            {
                ListNode *temp=curr->next->next;
                curr->next=temp;
                break;

            }
            curr=curr->next;
            
        }
        
    return head;
    }
};