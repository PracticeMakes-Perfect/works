/*
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

 

Example 1:

Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:

Input: root = [1,2]
Output: 1

 

Constraints:

    The number of nodes in the tree is in the range [1, 10^4].
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
    int dfs_postorder(TreeNode* root, int& cnt) {
        if (root == nullptr) {
            return 0;
        }

        int leftPath = dfs_postorder(root->left, cnt);
        int rightPath = dfs_postorder(root->right, cnt);
        
        cnt = std::max(cnt, leftPath + rightPath);

        return std::max(leftPath, rightPath) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int cnt = 0;

        //this is testing the idea of tree degree!!!
        //find the node where the sum of its longest left and right branches is maximized
        dfs_postorder(root, cnt);

        return cnt;
    }
};