/*
Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.

 

Example 1:

Input: head = [1,2,3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but its string representation as a ListNode is [].

Example 2:

Input: head = [1,2,3,4,5,6,7,8,9,10], k = 3
Output: [[1,2,3,4],[5,6,7],[8,9,10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.

 

Constraints:

    The number of nodes in the list is in the range [0, 1000].
    0 <= Node.val <= 1000
    1 <= k <= 50


*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        if (head == nullptr) {
            return vector<ListNode*>(k);
        }

        ListNode* now = head;
        int len = 0;
        while (now != nullptr) {
            ++len;
            now = now->next;
        }

        int part_len = len / k;
        int rest_len_cnt = len % k;

        std::vector<ListNode*> ans(k);
        now = head;
        ListNode* prev = now;
        for (int i = 0; i < k; ++i) {

            ListNode* new_part = now;
            int curr_len = part_len;

            if (rest_len_cnt > 0) {
                --rest_len_cnt;
                ++curr_len;
            }

            int j = 0;
            while (j < curr_len) {
                prev = now;
                if (now != nullptr) {
                    now = now->next;
                }

                ++j;
            }

            if (prev != nullptr) {
                prev->next = nullptr;
            }

            ans[i] = new_part;
        }

        return ans;
    }

};