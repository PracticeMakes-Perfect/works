/*
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

    KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
    int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.

 

Example 1:

Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8

 

Constraints:

    1 <= k <= 10^4
    0 <= nums.length <= 10^4
    -10^4 <= nums[i] <= 10^4
    -10^4 <= val <= 10^4
    At most 10^4 calls will be made to add.
    It is guaranteed that there will be at least k elements in the array when you search for the kth element.


*/

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (pq.size() < k) {
                pq.push(nums[i]);

            } else if (pq.top() < nums[i]) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        this->k = k;
    }
    
    int add(int val) {
        if (pq.size() < k) {
            pq.push(val);

        } else if (pq.top() < val) {
            pq.pop();
            pq.push(val);
        }

        if (pq.size() < k) {
            return -1;
        }

        return pq.top();
    }
private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */