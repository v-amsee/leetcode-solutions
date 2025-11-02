/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> TQ;
        TQ.push(root);
        int level=0;
        while(!TQ.empty())
        {
            int levelsize=TQ.size();
            for(int i=0;i<levelsize;i++)
            {   
                TreeNode*q= TQ.front();
                TQ.pop();
                if(q->left!=nullptr) TQ.push(q->left);
                if(q->right!=nullptr) TQ.push(q->right);
            }
            level++;

        }
    return level;}
};