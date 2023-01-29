/*What is Cache & LFU Cache ?
A cache is a data structure that stores a limited number of items and is used to quickly retrieve items that have been previously accessed.
An LFU cache evicts the least frequently used item when it reaches capacity, as opposed to an LRU (Least Recently Used) cache, which evicts the least recently used item.
Explanation to Approach :
Here we are using three maps to store the key-value pairs, the key-frequency pairs and the frequency-key pairs.
The implementation uses a combination of a HashMap and a LinkedHashSet to keep track of the keys and their frequencies, and to maintain the order of the keys.
When the cache reaches its maximum capacity, the least frequently used item will be removed.
This is done by keeping track of the number of times each item is accessed and removing the one that has been accessed the least amount of times.
The get() method returns the value associated with the given key, and updates the key's frequency.
The put() method adds a new key-value pair to the cache, and evicts the least frequently used key if the cache is at capacity.
Complexity
Time complexity : O(1)
Space complexity : O(n)*/


struct Node {
  int key;
  int value;
  int freq;
  list<int>::const_iterator it;
};

class LFUCache {
 public:
  LFUCache(int capacity) : capacity(capacity), minFreq(0) {}

  int get(int key) {
    if (!keyToNode.count(key))
      return -1;

    Node& node = keyToNode[key];
    touch(node);
    return node.value;
  }

  void put(int key, int value) {
    if (capacity == 0)
      return;
    if (keyToNode.count(key)) {
      Node& node = keyToNode[key];
      node.value = value;
      touch(node);
      return;
    }

    if (keyToNode.size() == capacity) {
      // Evict LRU key from the minFreq list
      const int keyToEvict = freqToList[minFreq].back();
      freqToList[minFreq].pop_back();
      keyToNode.erase(keyToEvict);
    }

    minFreq = 1;
    freqToList[1].push_front(key);
    keyToNode[key] = {key, value, 1, cbegin(freqToList[1])};
  }

 private:
  int capacity;
  int minFreq;
  unordered_map<int, Node> keyToNode;
  unordered_map<int, list<int>> freqToList;

  void touch(Node& node) {
    // Update the node's frequency
    const int prevFreq = node.freq;
    const int newFreq = ++node.freq;

    // Remove the iterator from prevFreq's list
    freqToList[prevFreq].erase(node.it);
    if (freqToList[prevFreq].empty()) {
      freqToList.erase(prevFreq);
      // Update minFreq if needed
      if (prevFreq == minFreq)
        ++minFreq;
    }

    // Insert the key to the front of newFreq's list
    freqToList[newFreq].push_front(node.key);
    node.it = cbegin(freqToList[newFreq]);
  }
};