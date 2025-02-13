/*
Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

 

Example 1:

Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]

Example 2:

Input: root = [1]
Output: ["1"]

 

Constraints:

    The number of nodes in the tree is in the range [1, 100].
    -100 <= Node.val <= 100


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
    void dfs_recursive(TreeNode* root, std::string curr, std::vector<std::string>& result) {
        if (root != nullptr) {
            curr += std::to_string(root->val);

            if (root->left == nullptr && root->right == nullptr) {
                result.push_back(curr);
            }

            if (root->left != nullptr) {
                dfs_recursive(root->left, curr + "->", result);
            }
            
            if (root->right != nullptr) {
                dfs_recursive(root->right, curr + "->", result);
            }
            
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        std::vector<std::string> result;
        
        dfs_recursive(root, "", result);

        return result;
    }
};