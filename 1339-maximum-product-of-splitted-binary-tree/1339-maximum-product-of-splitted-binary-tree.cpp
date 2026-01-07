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
    long long totalSum = 0;
    long long bestProduct = 0;   // renamed variable
    const int MOD = 1e9 + 7;

    // First DFS to calculate total sum
    long long getTotalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val 
             + getTotalSum(root->left) 
             + getTotalSum(root->right);
    }

    // Second DFS to calculate max product
    long long dfs(TreeNode* root) {
        if (!root) return 0;

        long long leftSum = dfs(root->left);
        long long rightSum = dfs(root->right);

        long long subtreeSum = root->val + leftSum + rightSum;

        // Try splitting at this edge
        bestProduct = max(bestProduct,
                          subtreeSum * (totalSum - subtreeSum));

        return subtreeSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = getTotalSum(root);
        dfs(root);
        return bestProduct % MOD;
    }
};
