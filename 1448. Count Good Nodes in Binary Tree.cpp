
//	o(n^2) Solution
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
    int ans=0;
    vector<int> path;
    void dfs(TreeNode* node,int &ans,vector<int> &path)
    {
        if(!node)
            return;
        int curr_max;
        if (path.empty()) curr_max = INT_MIN; 
        else curr_max = *max_element(path.begin(), path.end());
        if(node->val >=curr_max)
            ans++;
        path.push_back(node->val);
        dfs(node->left,ans,path);
        dfs(node->right,ans,path);
        path.pop_back();
    }
    int goodNodes(TreeNode* root) {
        
        dfs(root,ans,path);
    return ans;}
};

//O(n) Solution

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
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }

private:
    int dfs(TreeNode* node, int maxVal) {
        if (!node) {
            return 0;
        }

        int res = (node->val >= maxVal) ? 1 : 0;
        maxVal = max(maxVal, node->val);
        res += dfs(node->left, maxVal);
        res += dfs(node->right, maxVal);
        return res;
    }
};