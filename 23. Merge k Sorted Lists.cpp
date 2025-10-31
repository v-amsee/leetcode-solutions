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
    ListNode* mergetwolists(ListNode* l1, ListNode* l2)
    {
        ListNode dummy(0);
        ListNode* node = &dummy;
        while(l1!=nullptr && l2!=nullptr)
        {
            if(l1->val <= l2->val)
            {
                node->next=l1;
                l1=l1->next;
            }
            else
            {
                node->next=l2;
                l2=l2->next;
            }
            node=node->next;
        }
        if(l1)
        {
            node->next=l1;
        }
        if(l2)
        {
            node->next=l2;
        }
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==1)
            return lists[0];
        if(n==0)
            return {};
        
        for(int i=1;i<n;i++)
        {
            lists[i]=mergetwolists(lists[i-1],lists[i]);
        }
    return lists[n-1];
    }
};