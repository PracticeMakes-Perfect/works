/*
You are given some lists of regions where the first region of each list includes all other regions in that list.

Naturally, if a region x contains another region y then x is bigger than y. Also, by definition, a region x contains itself.

Given two regions: region1 and region2, return the smallest region that contains both of them.

If you are given regions r1, r2, and r3 such that r1 includes r3, it is guaranteed there is no r2 such that r2 includes r3.

It is guaranteed the smallest region exists.

 

Example 1:

Input:
regions = [["Earth","North America","South America"],
["North America","United States","Canada"],
["United States","New York","Boston"],
["Canada","Ontario","Quebec"],
["South America","Brazil"]],
region1 = "Quebec",
region2 = "New York"
Output: "North America"

Example 2:

Input: regions = [["Earth", "North America", "South America"],["North America", "United States", "Canada"],["United States", "New York", "Boston"],["Canada", "Ontario", "Quebec"],["South America", "Brazil"]], region1 = "Canada", region2 = "South America"
Output: "Earth"

 

Constraints:

    2 <= regions.length <= 10^4
    2 <= regions[i].length <= 20
    1 <= regions[i][j].length, region1.length, region2.length <= 20
    region1 != region2
    regions[i][j], region1, and region2 consist of English letters.


*/

class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        std::unordered_map<std::string, std::string> m;
        for (auto& r : regions) {
            std::string parent = r[0];
            for (int i = 1; i < r.size(); ++i) {
                m[r[i]] = parent;
            }
        }

        std::vector<std::string> path1 = dfs(region1, m);
        std::vector<std::string> path2 = dfs(region2, m);
        int i = 0;
        int j = 0;
        std::string lca;
        while (i < path1.size() && j < path2.size() && path1[i] == path2[j]) {
            lca = path1[i];
            ++i;
            ++j;
        }

        return lca;
    }

private:
    std::vector<std::string> dfs(std::string curr, std::unordered_map<std::string, std::string>& m) {
        std::vector<std::string> path;
        path.push_back(curr);

        while (m.find(curr) != m.end()) {
            std::string parent = m[curr];
            path.push_back(parent);
            curr = parent;
        }

        std::reverse(path.begin(), path.end());
        return path;
    }
};