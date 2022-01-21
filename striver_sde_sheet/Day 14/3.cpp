#include <bits/stdc++.h>
using namespace std;

// LFU Cache
// https://leetcode.com/problems/lfu-cache/

class LFUCache
{
    int capacity;
    int size = 0;
    // freq -> listOfKey following LRU
    unordered_map<int, list<int>> freq;
    // key -> value
    unordered_map<int, int> vals;
    // key -> pairOfFreqIterator
    unordered_map<int, pair<int, list<int>::iterator>> m;
    int leastFreq = 0;

public:
    LFUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (capacity == 0)
            return -1;
        if (m.find(key) == m.end())
            return -1;
        pair<int, list<int>::iterator> p = m[key];
        int f = p.first;
        int k = *(p.second);
        freq[f].erase(p.second);
        freq[f + 1].push_front(k);
        m[key] = {f + 1, freq[f + 1].begin()};
        if (leastFreq == f && freq[f].size() == 0)
            leastFreq = f + 1;
        return vals[key];
    }

    void put(int key, int value)
    {
        if (capacity == 0)
            return;
        if (m.find(key) == m.end())
        {
            if (size == capacity)
            {
                int remove = freq[leastFreq].back();
                freq[leastFreq].pop_back();
                m.erase(remove);
            }
            freq[1].push_front(key);
            m[key] = {1, freq[1].begin()};
            leastFreq = 1;
            size = min(capacity, size + 1);
        }
        else
        {
            pair<int, list<int>::iterator> p = m[key];
            int f = p.first;
            freq[f].erase(p.second);
            freq[f + 1].push_front(key);
            m[key] = {f + 1, freq[f + 1].begin()};
            if (leastFreq == f && freq[f].size() == 0)
                leastFreq = f + 1;
        }
        vals[key] = value;
    }
};