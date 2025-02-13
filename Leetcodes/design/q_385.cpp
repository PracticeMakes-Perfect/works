/*
Given a string s represents the serialization of a nested list, implement a parser to deserialize it and return the deserialized NestedInteger.

Each element is either an integer or a list whose elements may also be integers or other lists.

 

Example 1:

Input: s = "324"
Output: 324
Explanation: You should return a NestedInteger object which contains a single integer 324.

Example 2:

Input: s = "[123,[456,[789]]]"
Output: [123,[456,[789]]]
Explanation: Return a NestedInteger object containing a nested list with 2 elements:
1. An integer containing value 123.
2. A nested list containing two elements:
    i.  An integer containing value 456.
    ii. A nested list with one element:
         a. An integer containing value 789

 

Constraints:

    1 <= s.length <= 5 * 10^4
    s consists of digits, square brackets "[]", negative sign '-', and commas ','.
    s is the serialization of valid NestedInteger.
    All the values in the input are in the range [-10^6, 10^6].


*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        //return by_stack(s);
        int pos = 0;
        return recursive(s, pos);
    }

private:
    NestedInteger recursive(const string& s, int& pos) {
        if (s[pos] == '[') {
            if (s[pos + 1] == ']') {
                pos += 2;
                return NestedInteger();
            }

            NestedInteger ans;
            while (s[pos] != ']') {
                ++pos;
                ans.add(recursive(s, pos));
            }

            ++pos;
            return ans;

        } else {

            int value = 0;
            int mul = 1;

            if (s[pos] == '-') {
                mul = -1;
                ++pos;
            }

            while (pos < s.length() && s[pos] >= '0' && s[pos] <= '9') {
                value *= 10;
                value += (s[pos] - '0');
                ++pos;
            }

            return NestedInteger(value * mul);
        }
    }

    NestedInteger by_stack(string& s) {
        std::function<bool(char)> is_num = [](char c) { 
            return (c == '-') || std::isdigit(c);
        };

        std::stack<NestedInteger> stack;
        stack.push(NestedInteger());

        for (auto it = s.begin(); it != s.end();) {
            const char& c = *it;

            if (is_num(c)) {
                auto it2 = std::find_if_not(it, s.end(), is_num);
                int val = std::stoi(std::string(it, it2));

                stack.top().add(NestedInteger(val));
                it = it2;

            } else {
                if (c == '[') {
                    stack.push(NestedInteger());

                } else if (c == ']') {
                    NestedInteger ni = stack.top();
                    stack.pop();

                    stack.top().add(ni);
                }

                ++it;
            }
        }

        return stack.top().getList().front();
    }
};