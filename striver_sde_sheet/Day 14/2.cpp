#include <bits/stdc++.h>
using namespace std;

// LRU Cache
// https://leetcode.com/problems/lru-cache/submissions/

class LRUCache
{
private:
    int capacity;
    // Doubly linked list <key, value>
    list<pair<int, int>> q;
    // <key, iterator to node corresponding to key>
    unordered_map<int, list<pair<int, int>>::iterator> m;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (m.find(key) == m.end())
            return -1;
        pair<int, int> p = *m[key];
        q.erase(m[key]);
        q.push_front(p);
        m[key] = q.begin();
        return (*m[key]).second;
    }

    void put(int key, int value)
    {
        if (m.find(key) == m.end())
        {
            if (q.size() == capacity)
            {
                int remove = q.back().first;
                q.pop_back();
                m.erase(remove);
            }
        }
        else
        {
            q.erase(m[key]);
        }
        q.push_front({key, value});
        m[key] = q.begin();
    }
};