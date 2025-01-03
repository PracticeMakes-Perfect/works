/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: 2

Example 2:

Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5

 

Constraints:

    The number of nodes in the tree is in the range [0, 10^5].
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
private:
    int bfs_iterative(TreeNode* root) {
        int mindepth = 100001;
        int depthNow = 1;

        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int len = q.size();

            for (int i = 0; i < len; ++i) {

                TreeNode* n = q.front();
                q.pop();

                if (n == nullptr) {
                    continue;
                }

                if (n->left == nullptr && n->right == nullptr) {
                    mindepth = std::min(mindepth, depthNow);

                    return mindepth;
                }
                
                if (n->left != nullptr) {
                    q.push(n->left);
                }

                if (n->right != nullptr) {
                    q.push(n->right);
                }
            }

            ++depthNow;
            
        }

        return mindepth;
    }
    void dfs(TreeNode* root, int depthNow, int& minDepth) {
        if (root == nullptr) {
            return;
        }

        if (root->left == nullptr && root->right == nullptr) {
            minDepth = std::min(minDepth, depthNow);
            return;
        }

        dfs(root->left, depthNow + 1, minDepth);
        dfs(root->right, depthNow + 1, minDepth);
    }
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        /*
        int minDepth = 100001;
        dfs(root, 1, minDepth);

        return minDepth;
        */

        return bfs_iterative(root);
    }
};