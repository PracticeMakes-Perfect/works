/*
Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

    void add(key) Inserts the value key into the HashSet.
    bool contains(key) Returns whether the value key exists in the HashSet or not.
    void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.

 

Example 1:

Input
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
Output
[null, null, null, true, false, null, true, null, false]

Explanation
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // return True
myHashSet.contains(3); // return False, (not found)
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // return True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // return False, (already removed)

 

Constraints:

    0 <= key <= 10^6
    At most 104 calls will be made to add, remove, and contains.


*/


class MyHashSet {
public:
    MyHashSet() {
        keyRange = 769;
        buckets = std::vector<std::vector<int>>(keyRange, std::vector<int>(1, -1));
        
    }
    
    void add(int key) {
        index = hashIt(key);
        
        if (!contains(key)) {
            buckets[index].push_back(key);    
        }
    }
    
    void remove(int key) {
        index = hashIt(key);
        
        for (std::vector<int>::iterator it = buckets[index].begin(); it != buckets[index].end(); ++it){
            
            if (*it == key) {
                buckets[index].erase(it);
                break;
            }
        }       
    }
    
    bool contains(int key) {
        index = hashIt(key);
        
        int result = false;
        for (auto target : buckets[index]) {
            if (target == key) {
                result = true;
                break;
            }
        }
        return result;
    }
private:
    //100003 is a prime number
    std::vector<std::vector<int>> buckets;
    int keyRange;
    int index;
    
    int hashIt(int key) {
        return (key % keyRange);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */