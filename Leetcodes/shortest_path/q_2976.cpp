/*
You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].

You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.

Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.

Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

 

Example 1:

Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
Output: 28
Explanation: To convert the string "abcd" to string "acbe":
- Change value at index 1 from 'b' to 'c' at a cost of 5.
- Change value at index 2 from 'c' to 'e' at a cost of 1.
- Change value at index 2 from 'e' to 'b' at a cost of 2.
- Change value at index 3 from 'd' to 'e' at a cost of 20.
The total cost incurred is 5 + 1 + 2 + 20 = 28.
It can be shown that this is the minimum possible cost.

Example 2:

Input: source = "aaaa", target = "bbbb", original = ["a","c"], changed = ["c","b"], cost = [1,2]
Output: 12
Explanation: To change the character 'a' to 'b' change the character 'a' to 'c' at a cost of 1, followed by changing the character 'c' to 'b' at a cost of 2, for a total cost of 1 + 2 = 3. To change all occurrences of 'a' to 'b', a total cost of 3 * 4 = 12 is incurred.

Example 3:

Input: source = "abcd", target = "abce", original = ["a"], changed = ["e"], cost = [10000]
Output: -1
Explanation: It is impossible to convert source to target because the value at index 3 cannot be changed from 'd' to 'e'.

 

Constraints:

    1 <= source.length == target.length <= 105
    source, target consist of lowercase English letters.
    1 <= cost.length == original.length == changed.length <= 2000
    original[i], changed[i] are lowercase English letters.
    1 <= cost[i] <= 106
    original[i] != changed[i]


*/

class Solution {
private:
    long long by_floyd_warshall(string& source, string& target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        
        std::vector<std::vector<long long>> min_cost(26, std::vector<long long>(26, INT_MAX));

        for (int i = 0; i < original.size(); ++i) {
            int s = original[i] - 'a';
            int e = changed[i] - 'a';

            min_cost[s][e] = std::min(min_cost[s][e], (long long)cost[i]);
        }

        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    min_cost[i][j] = std::min(min_cost[i][j], min_cost[i][k] + min_cost[k][j]);
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < source.size(); ++i) {
            if (source[i] == target[i]) {
                continue;
            }

            int src = source[i] - 'a';
            int trg = target[i] - 'a';

            if (min_cost[src][trg] >= INT_MAX) {
                return -1;
            }

            ans += min_cost[src][trg];
        }

        return ans;
    }
    long long by_dijkstra(string& source, string& target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        std::vector<std::vector<std::pair<int, int>>> adj(26);

        for (int i = 0; i < original.size(); ++i) {
            adj[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }

        std::vector<std::vector<long long>> min_cost(26, std::vector<long long>(26, -1));

        for (int i = 0; i < 26; ++i) {

            //doing dijkstra
            std::priority_queue<std::pair<long long, int>, 
                                std::vector<std::pair<long long, int>>, 
                                std::greater<std::pair<long long, int>>> pq;

            pq.push({0, i});
            while (!pq.empty()) {
                auto [curr_cost, curr_i] = pq.top();
                pq.pop();

                if (min_cost[i][curr_i] != -1 && min_cost[i][curr_i] < curr_cost) {
                    continue;
                }

                for (auto& [target_i, convert_cost] : adj[curr_i]) {
                    long long new_cost = curr_cost + convert_cost;

                    if (min_cost[i][target_i] == -1 || new_cost < min_cost[i][target_i]) {
                        min_cost[i][target_i] = new_cost;

                        pq.push({new_cost, target_i});
                    }
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < source.size(); ++i) {
            if (source[i] != target[i]) {
                long long convert_cost = min_cost[source[i] - 'a'][target[i] - 'a'];

                if (convert_cost == -1) {
                    return -1;
                }

                ans += convert_cost;
            }
        }

        return ans;
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {

        return by_dijkstra(source, target, original, changed, cost);
        //return by_floyd_warshall(source, target, original, changed, cost);
    }
};