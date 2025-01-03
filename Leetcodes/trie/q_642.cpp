/*
Design a search autocomplete system for a search engine. Users may input a sentence (at least one word and end with a special character '#').

You are given a string array sentences and an integer array times both of length n where sentences[i] is a previously typed sentence and times[i] is the corresponding number of times the sentence was typed. For each input character except '#', return the top 3 historical hot sentences that have the same prefix as the part of the sentence already typed.

Here are the specific rules:

    The hot degree for a sentence is defined as the number of times a user typed the exactly same sentence before.
    The returned top 3 hot sentences should be sorted by hot degree (The first is the hottest one). If several sentences have the same hot degree, use ASCII-code order (smaller one appears first).
    If less than 3 hot sentences exist, return as many as you can.
    When the input is a special character, it means the sentence ends, and in this case, you need to return an empty list.

Implement the AutocompleteSystem class:

    AutocompleteSystem(String[] sentences, int[] times) Initializes the object with the sentences and times arrays.
    List<String> input(char c) This indicates that the user typed the character c.
        Returns an empty array [] if c == '#' and stores the inputted sentence in the system.
        Returns the top 3 historical hot sentences that have the same prefix as the part of the sentence already typed. If there are fewer than 3 matches, return them all.

 

Example 1:

Input
["AutocompleteSystem", "input", "input", "input", "input"]
[[["i love you", "island", "iroman", "i love leetcode"], [5, 3, 2, 2]], ["i"], [" "], ["a"], ["#"]]
Output
[null, ["i love you", "island", "i love leetcode"], ["i love you", "i love leetcode"], [], []]

Explanation
AutocompleteSystem obj = new AutocompleteSystem(["i love you", "island", "iroman", "i love leetcode"], [5, 3, 2, 2]);
obj.input("i"); // return ["i love you", "island", "i love leetcode"]. There are four sentences that have prefix "i". Among them, "ironman" and "i love leetcode" have same hot degree. Since ' ' has ASCII code 32 and 'r' has ASCII code 114, "i love leetcode" should be in front of "ironman". Also we only need to output top 3 hot sentences, so "ironman" will be ignored.
obj.input(" "); // return ["i love you", "i love leetcode"]. There are only two sentences that have prefix "i ".
obj.input("a"); // return []. There are no sentences that have prefix "i a".
obj.input("#"); // return []. The user finished the input, the sentence "i a" should be saved as a historical sentence in system. And the following input will be counted as a new search.

 

Constraints:

    n == sentences.length
    n == times.length
    1 <= n <= 100
    1 <= sentences[i].length <= 100
    1 <= times[i] <= 50
    c is a lowercase English letter, a hash '#', or space ' '.
    Each tested sentence will be a sequence of characters c that end with the character '#'.
    Each tested sentence will have a length in the range [1, 200].
    The words in each input sentence are separated by single spaces.
    At most 5000 calls will be made to input.


*/

class AutocompleteSystem {
private:
    struct greaterPair {
        bool operator() (const std::pair<std::string, int> p1, const std::pair<std::string, int> p2) const { 
            if (p1.second == p2.second) {
                int rtn = p1.first.compare(p2.first);
                if (rtn > 0) {
                    return true;
                }

                return false;
            }

            return p1.second < p2.second; 
        }
    };

    struct TrieNode {
        std::map<char, TrieNode*> children;
        std::unordered_map<std::string, int> sentences;

        TrieNode() {

        }
    };
    
    TrieNode* root;
    TrieNode* curr;
    TrieNode* dead;
    std::string currSentence = "";

    void insertTrie(std::string sentence, int count) {

        TrieNode* now = root;
        for (const char ch : sentence) {
            if (now->children.find(ch) == now->children.end()) {
                now->children.insert(std::make_pair(ch, new TrieNode()));
            }

            now = now->children[ch];

            //check if sentence exists in that node
            if (now->sentences.find(sentence) == now->sentences.end()) {
                now->sentences.insert(std::make_pair(sentence, count));
            } else {
                now->sentences[sentence] += count;
            }
            
        }
    }

public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new TrieNode();

        for (int i = 0; i < sentences.size(); ++i) {
            insertTrie(sentences[i], times[i]);
        }

        curr = root;
        dead = new TrieNode();  //this is for no more search.
    }
    
    vector<string> input(char c) {
        //condition 1, if '#'
        if (c == '#') {
            insertTrie(currSentence, 1);
            currSentence = "";
            curr = root;

            return {};
        }

        //condition 2, if not '#', but we could not find this char
        currSentence += c;
        if (curr->children.find(c) == curr->children.end()) {
            curr = dead;
            return {};
        }

        //condition 3, we find it and add to return list
        curr = curr->children[c];
        std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, greaterPair> pq;
        
        //std::vector<std::string> sentences_now;
        for (const auto& pair : curr->sentences) {
            pq.push(pair);
        }

        //if priority_queue size is larger than 3, only get top 3, 
        //else we get them all.
        std::vector<std::string> result;
        int pq_size = pq.size();
        int len = std::min(3, pq_size);
        for (int i = 0; i < len; ++i) {
            result.push_back(pq.top().first);
            pq.pop();
        }

        return result;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */