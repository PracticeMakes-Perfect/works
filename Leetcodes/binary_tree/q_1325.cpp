/*
Given a binary tree root and an integer target, delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, if its parent node becomes a leaf node and has the value target, it should also be deleted (you need to continue doing that until you cannot).

 

Example 1:

Input: root = [1,2,3,2,null,2,4], target = 2
Output: [1,null,3,null,4]
Explanation: Leaf nodes in green with value (target = 2) are removed (Picture in left). 
After removing, new nodes become leaf nodes with value (target = 2) (Picture in center).

Example 2:

Input: root = [1,3,3,3,2], target = 3
Output: [1,3,null,null,2]

Example 3:

Input: root = [1,2,null,2,null,2], target = 2
Output: [1]
Explanation: Leaf nodes in green with value (target = 2) are removed at each step.

 

Constraints:

    The number of nodes in the tree is in the range [1, 3000].
    1 <= Node.val, target <= 1000


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
    TreeNode* dfs_postorder(TreeNode* root, int target) {
        //l_r: left or right; left: 0, right: 1, root: -1
        std::function<TreeNode*(TreeNode*)> post = [&](TreeNode* now) -> TreeNode* {
            if (now == nullptr) {
                return nullptr;
            }

            now->left = post(now->left);
            now->right = post(now->right);

            if (now->left == nullptr && now->right == nullptr && now->val == target) {
                now = nullptr;
            }
            
            return now;
        };

        root = post(root);

        return root;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return dfs_postorder(root, target);
    }
};