class Solution {
public:
    void backtrack(int open, int close, int n, vector<string>& ans, string& stack) {
        if (open == close && open == n) {
            ans.push_back(stack);
            return;
        }

        if (open < n) {
            stack += '(';
            backtrack(open + 1, close, n, ans, stack);
            stack.pop_back();
        }
        if (close < open) {
            stack += ')';
            backtrack(open, close + 1, n, ans, stack);
            stack.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string stack;
        backtrack(0, 0, n, ans, stack);
        return ans; 
    }
};