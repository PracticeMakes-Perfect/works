/*
You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.

Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

As a reminder, any shorter prefix of a string is lexicographically smaller.

    For example, "ab" is lexicographically smaller than "aba".

A leaf of a node is a node that has no children.

 

Example 1:

Input: root = [0,1,2,3,4,3,4]
Output: "dba"

Example 2:

Input: root = [25,1,3,1,3,0,2]
Output: "adz"

Example 3:

Input: root = [2,2,1,null,1,0,null,0]
Output: "abc"

 

Constraints:

    The number of nodes in the tree is in the range [1, 8500].
    0 <= Node.val <= 25


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
    std::string recursive(TreeNode* root) {
        std::string ans{};

        std::function<void(TreeNode*, std::string)> re = [&](TreeNode* now, std::string currStr) {
            if (now == nullptr) {
                return;
            }

            currStr = char(now->val + 'a') + currStr;

            if (now->left == nullptr && now->right == nullptr) {

                if (ans == "" || ans > currStr) {
                    ans = currStr;
                }
            }

            if (now->left != nullptr) {
                re(now->left, currStr);
            }

            if (now->right != nullptr) {
                re(now->right, currStr);
            }
        };

        re(root, "");

        return ans;
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        return recursive(root);
    }
};