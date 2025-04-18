/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

Note that division between two integers should truncate toward zero.

It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

 

Constraints:

    1 <= tokens.length <= 10^4
    tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].


*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::vector<long> stack;
        std::string::size_type result;
        std::string symbols = "+-*/";
        long num01 = 0;
        long num02 = 0;
        long cal = 0;
        
        for (std::string token : tokens) {
            result = symbols.find(token);
            
            if (result == std::string::npos) {
                stack.push_back(std::stoi(token));
                continue;
            }
            
            num02 = stack.back();
            stack.pop_back();
            num01 = stack.back();
            stack.pop_back();
            
            cal = 0;
            
            if ((token.compare("+")) == 0) {
                cal = num01 + num02;
            } else if ((token.compare("-")) == 0) {
                cal = num01 - num02;
            } else if ((token.compare("*")) == 0) {
                cal = num01 * num02;
            } else if ((token.compare("/")) == 0) {
                cal = num01 / num02;
            } else {
                continue;
            }
            
            stack.push_back(cal);
        }
        
        return (int)stack.back();
    }
};