//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

#include <unordered_map>
#include <list>

class LRUCache {
public:
    LRUCache(int cap) {
        capacity = cap;
    }
    
    int GET(int key) {
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;  // Key not found
        } else {
            // Move the accessed item to the front of the list (most recently used)
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            return cacheMap[key]->second;
        }
    }
    
    void SET(int key, int value) {
        if (cacheMap.find(key) != cacheMap.end()) {
            // If key exists, update the value and move the node to the front
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key]->second = value;
        } else {
            if (cacheList.size() == capacity) {
                // Remove the least recently used item
                int lruKey = cacheList.back().first;
                cacheList.pop_back();
                cacheMap.erase(lruKey);
            }
            // Insert the new key-value pair at the front
            cacheList.push_front({key, value});
            cacheMap[key] = cacheList.begin();
        }
    }

private:
    int capacity;
    std::list<std::pair<int, int>> cacheList; // Doubly linked list to store keys and values
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cacheMap; // Hashmap to store key-node pairs
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends