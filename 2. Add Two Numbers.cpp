//Brute Force - Wont be accepted

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        string a,b;
        while(l1!=nullptr)
        {
            a+=to_string(l1->val);
            l1=l1->next;
        }
        while(l2!=nullptr)
        {
            b+=to_string(l2->val);
            l2=l2->next;
        }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        long long p=stoll(a),q=stoll(b);
        long long r= p+q;
        string c=to_string(r);
        reverse(c.begin(),c.end());

        ListNode *l3= new ListNode(c[0]-'0');
        ListNode *temp=l3;
        int i=1,n=c.size();
        while(i<n)
        {
            ListNode *newnode =new ListNode(c[i]-'0');
            temp->next=newnode;
            temp=newnode;
            i++;
        }
    return l3;
    }
};

//Optimal Solution

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0,number,digit;
        ListNode *dummy= new ListNode(0);
        ListNode *mover=dummy;
        
        while(l1 || l2||carry)
      {
            int val1=(l1?l1->val:0);
            int val2=(l2?l2->val:0);
            number=val1 + val2 +carry;
            digit=number%10;
            mover->next=new ListNode(digit);
            mover=mover->next;
            carry=number/10;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
            

        }

    return dummy->next;
    }
};