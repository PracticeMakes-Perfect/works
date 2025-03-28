/*
Given two binary trees original and cloned and given a reference to a node target in the original tree.

The cloned tree is a copy of the original tree.

Return a reference to the same node in the cloned tree.

Note that you are not allowed to change any of the two trees or the target node and the answer must be a reference to a node in the cloned tree.

 

Example 1:

Input: tree = [7,4,3,null,null,6,19], target = 3
Output: 3
Explanation: In all examples the original and cloned trees are shown. The target node is a green node from the original tree. The answer is the yellow node from the cloned tree.

Example 2:

Input: tree = [7], target =  7
Output: 7

Example 3:

Input: tree = [8,null,6,null,5,null,4,null,3,null,2,null,1], target = 4
Output: 4

 

Constraints:

    The number of nodes in the tree is in the range [1, 10^4].
    The values of the nodes of the tree are unique.
    target node is a node from the original tree and is not null.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    TreeNode* dfs(TreeNode* o_now, TreeNode* c_now, TreeNode* target) {
        if (o_now == nullptr) {
            return nullptr;
        }

        if (o_now->val == target->val) {
            return c_now;
        }

        TreeNode* goLeft = dfs(o_now->left, c_now->left, target);

        if (goLeft != nullptr && goLeft->val == target->val) {
            return goLeft;
        }

        TreeNode* goRight = dfs(o_now->right, c_now->right, target);

        if (goRight != nullptr && goRight->val == target->val) {
            return goRight;
        }

        return nullptr;
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {

        
        return dfs(original, cloned, target);
    }
};