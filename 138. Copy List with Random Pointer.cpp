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
        if (!head)
            return nullptr;
        Node *newhead = new Node(head->val);
        Node *temp=head,*prev=newhead;
        unordered_map<Node*,int> org;
        unordered_map<int,Node*> copy;
        org[head]=0;
        copy[0]=newhead;
        int index=1;
        while(temp!=nullptr)
        {   
            temp=temp->next;
            if(temp!=nullptr)
            {   
                org[temp]=index;
                Node *newnode = new Node(temp->val);
                copy[index]=newnode;
                index++;
                prev->next= newnode;
                prev= newnode;

            }
            else
            {
                prev->next=nullptr;
                prev=nullptr;
            }
        }
    Node *tmp1=head,*tmp2=newhead;

    while(tmp2!=nullptr)
    {   
        if(tmp1->random!=nullptr)
        {
        tmp2->random=copy[org[tmp1->random]];
        }
        else
        {
            tmp2->random=nullptr;
        }
        tmp1=tmp1->next;
        tmp2=tmp2->next;
    }

   return  newhead;
    }
};


//Less Complicated HashMap Solution

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
        unordered_map<Node*, Node*> oldToCopy;
        oldToCopy[nullptr] = nullptr;

        Node* cur = head;
        while (cur != nullptr) {
            if (oldToCopy.find(cur) == oldToCopy.end()) {
                oldToCopy[cur] = new Node(0);
            }
            oldToCopy[cur]->val = cur->val;
            if (oldToCopy.find(cur->next) == oldToCopy.end()) {
                oldToCopy[cur->next] = new Node(0);
            }
            oldToCopy[cur]->next = oldToCopy[cur->next];
            if (oldToCopy.find(cur->random) == oldToCopy.end()) {
                oldToCopy[cur->random] = new Node(0);
            }
            oldToCopy[cur]->random = oldToCopy[cur->random];
            cur = cur->next;
        }
        return oldToCopy[head];
    }
};

//Space Optimized solution