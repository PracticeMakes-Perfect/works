/*
Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.

The encoded string should be as compact as possible.

 

Example 1:

Input: root = [2,1,3]
Output: [2,1,3]

Example 2:

Input: root = []
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [0, 10^4].
    0 <= Node.val <= 104
    The input tree is guaranteed to be a binary search tree.


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
class Codec {
private:
    void post_order(std::string& s, TreeNode* root) {
        if (root == nullptr) {
            return;
        }

        post_order(s, root->left);
        post_order(s, root->right);
        s += std::to_string(root->val) + ",";
    }

    TreeNode* de_helper(std::vector<int>& int_data, int lower, int upper) {
        if (int_data.empty()) {
            return nullptr;
        }

        int val = int_data.back();
        if (val < lower || val > upper) {
            return nullptr;
        }

        int_data.pop_back();
        TreeNode* root = new TreeNode(val);
        root->right = de_helper(int_data, val, upper);
        root->left = de_helper(int_data, lower, val);

        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        std::string s;
        post_order(s, root);
        
        if (!s.empty() && s.back() == ',') {
            s.pop_back();
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        std::vector<int> int_data;
        std::stringstream ss(data);
        std::string str;
        while (std::getline(ss, str, ',')) {
            int_data.push_back(std::stoi(str));
        }

        return de_helper(int_data, INT_MIN, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;