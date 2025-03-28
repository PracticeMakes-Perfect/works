/*
Given the root of a binary tree, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, and return it.

Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.

 

Example 1:

Input: root = [1,2,3,4]
Output: "1(2(4))(3)"
Explanation: Originally, it needs to be "1(2(4)())(3()())", but you need to omit all the unnecessary empty parenthesis pairs. And it will be "1(2(4))(3)"

Example 2:

Input: root = [1,2,3,null,4]
Output: "1(2()(4))(3)"
Explanation: Almost the same as the first example, except we cannot omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.

 

Constraints:

    The number of nodes in the tree is in the range [1, 10^4].
    -1000 <= Node.val <= 1000


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
    void dfs_recursive(TreeNode* root, std::string& result) {
        if (root != nullptr) {

            result += std::to_string(root->val);

            if (root->left == nullptr && root->right == nullptr) {
                return;
            }

            result += "(";
            dfs_recursive(root->left, result);
            result += ")";

            //only non- null right child should add parenthesis
            if (root->right != nullptr) {
                result += "(";
                dfs_recursive(root->right, result);
                result += ")";
            }
        }
    }
public:
    string tree2str(TreeNode* root) {
        std::string result;

        dfs_recursive(root, result);

        return result;
    }
};