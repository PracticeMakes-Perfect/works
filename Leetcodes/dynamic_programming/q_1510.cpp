/*
Alice and Bob take turns playing a game, with Alice starting first.

Initially, there are n stones in a pile. On each player's turn, that player makes a move consisting of removing any non-zero square number of stones in the pile.

Also, if a player cannot make a move, he/she loses the game.

Given a positive integer n, return true if and only if Alice wins the game otherwise return false, assuming both players play optimally.

 

Example 1:

Input: n = 1
Output: true
Explanation: Alice can remove 1 stone winning the game because Bob doesn't have any moves.

Example 2:

Input: n = 2
Output: false
Explanation: Alice can only remove 1 stone, after that Bob removes the last one winning the game (2 -> 1 -> 0).

Example 3:

Input: n = 4
Output: true
Explanation: n is already a perfect square, Alice can win with one move, removing 4 stones (4 -> 0).

 

Constraints:

    1 <= n <= 10^5


*/

class Solution {
private:
    bool iterative(int n) {
        bool mem[n + 1];
        memset(mem, 0, sizeof(mem));

        for (int i = 1; i < n + 1; ++i) {
            for (int k = 1; k * k <= i; ++k) {
                
                if (!mem[i - k * k]) {
                    mem[i] = true;
                    break;
                }
            }
        }

        return mem[n];
    }
    bool recursive(int n) {
        std::vector<int> mem(n + 1, -1);
        //std::unordered_map<int, int> mem;
        mem[0] = 0;

        std::function<bool(int)> recurr = [&](int remain) -> bool {
            if (remain <= 0) {
                return 0;
            }

            /*
            if (mem.find(remain) != mem.end()) {
                return mem[remain];
            }*/
            if (mem[remain] != -1) {
                return mem[remain];
            }

            int sqrt = std::sqrt(remain);
            for (int i = 1; i <= sqrt; ++i) {

                if (!recurr(remain - i * i)) {
                    
                    return mem[remain] = 1;
                }
            }

            return mem[remain] = 0;
        };

        return recurr(n);
    }
public:
    bool winnerSquareGame(int n) {
        //return recursive(n);        
        return iterative(n);
    }
};