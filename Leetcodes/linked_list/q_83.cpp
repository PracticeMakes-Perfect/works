/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 

Example 1:

Input: head = [1,1,2]
Output: [1,2]

Example 2:

Input: head = [1,1,2,3,3]
Output: [1,2,3]

 

Constraints:

    The number of nodes in the list is in the range [0, 300].
    -100 <= Node.val <= 100
    The list is guaranteed to be sorted in ascending order.


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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* ptr1 = head;
        ListNode* ptr2 = nullptr;

        while (ptr1 != nullptr) {

            ListNode* tmp = nullptr;
            ptr2 = ptr1->next;
            while (ptr2 != nullptr && ptr1->val == ptr2->val) {
                tmp = ptr2->next;
                ptr2->val = 0;
                ptr2->next = nullptr;
                ptr2 = tmp;
            }

            ptr1->next = ptr2;
            ptr1 = ptr1->next;
        }

        return head;
    }
};
