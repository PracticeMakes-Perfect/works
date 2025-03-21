/*
Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

 

Example 1:

Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]

Example 2:

Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]

 

Constraints:

    The number of nodes in the tree is in the range [0, 104].
    0 <= Node.val <= 104
    The height of the n-ary tree is less than or equal to 1000.

*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if (root == NULL) {
            return result;
        }

        //recursion_traverse(root);
        byIter(root);
        return result;
    }

private:
    std::vector<int> result;

    void recursion_traverse(Node* curr) {
        if (curr == NULL) {
            return;
        }

        int val = curr->val;
        result.push_back(val);
        std::vector<Node*> curr_children = curr->children;

        for (int i = 0; i < curr_children.size(); ++i) {
            recursion_traverse(curr_children[i]);
        }
    }

    void byIter(Node* root) {
        std::stack<Node*> pre;
        int t_val = 0;
        Node* curr = NULL;
        std::vector<Node*> curr_children;

        pre.push(root);

        while(pre.size() > 0) {
            curr = pre.top();
            pre.pop();
            t_val = curr->val;

            result.push_back(t_val);

            if (!(curr->children).empty()) {
                curr_children = curr->children;

                for (int i = curr_children.size() - 1; i > -1; --i) {
                    pre.push(curr_children[i]);
                }
            }
        }
    }
};