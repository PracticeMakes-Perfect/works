/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:

Input: strs = [""]
Output: [[""]]

Example 3:

Input: strs = ["a"]
Output: [["a"]]

 

Constraints:

    1 <= strs.length <= 10^4
    0 <= strs[i].length <= 100
    strs[i] consists of lowercase English letters.


*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> result = std::vector<std::vector<std::string>>();
        std::unordered_map<std::string, std::vector<std::string>> m;
        
        std::string key;
        for (int i = 0; i < strs.size(); ++i) {
            key = strs[i];
            std::sort(key.begin(), key.end());
            
            if (m.find(key) == m.end()) {
                m.insert(std::make_pair(key, std::vector<std::string>()));
                m[key].push_back(strs[i]);
                
            } else {
                m[key].push_back(strs[i]);
            }
        }
        
        for (auto i : m) {
            result.push_back(i.second);
        }
        
        return result;
        
    }
};