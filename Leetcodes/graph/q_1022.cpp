/*
You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.

    For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.

The test cases are generated so that the answer fits in a 32-bits integer.

 

Example 1:

Input: root = [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

Example 2:

Input: root = [0]
Output: 0

 

Constraints:

    The number of nodes in the tree is in the range [1, 1000].
    Node.val is 0 or 1.


*/

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
private:
    int dfs_iterative(TreeNode* root) {

        std::stack<std::pair<TreeNode*, int>> s;
        s.push({root, 0});
        int result = 0;

        while (!s.empty()) {
            std::pair<TreeNode*, int> p = s.top();
            s.pop();

            TreeNode* n = p.first;
            int currVal = p.second;

            if (n != nullptr) {
                currVal = (currVal << 1) | n->val;

                if (n->left == nullptr && n->right == nullptr) {
                    result += currVal;
                } else {
                    s.push(std::make_pair(n->left, currVal));
                    s.push(std::make_pair(n->right, currVal));
                }
            }
        }

        return result;
    }
    void dfs_recursive(TreeNode* root, int currVal, int& val) {
        if (root != nullptr) {

            currVal = (currVal << 1) | root->val;

            if (root->left == nullptr && root->right == nullptr) {
                val += currVal;
            }

            dfs_recursive(root->left, currVal, val);
            dfs_recursive(root->right, currVal, val);
        }
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        /*
        int val = 0;
        dfs_recursive(root, 0, val);

        return val;
        */

        return dfs_iterative(root);
    }
};