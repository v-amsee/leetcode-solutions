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
    int MaxHeightOfBinaryTree(TreeNode *root)
    {
        if (root==nullptr)
            return 0;

        return 1 + max(MaxHeightOfBinaryTree(root->left),MaxHeightOfBinaryTree(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
         if (!root) return 0;
        int lh=MaxHeightOfBinaryTree(root->left);
        int rh=MaxHeightOfBinaryTree(root->right);
        int diameter=lh +rh;
        int sub = max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right));
        return max(diameter,sub);
        
    }
};

//Optimal solution

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
    int dfs(TreeNode *root,int& ans)
    {
        if (root==nullptr)
            return 0;
        int left=dfs(root->left,ans);
        int right=dfs(root->right,ans);
    ans=max(ans,left +right);
    return 1 + max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;

        dfs(root,ans);
        return ans;
       
    }
};