#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Custom Vector (wrapper over std::vector)
template<typename T>
class CustomVector {
public:
    vector<T> elements;
    void push_back(T value) { elements.push_back(value); }
    T& operator[](int index) { return elements[index]; }
    int size() { return elements.size(); }
};

// Stack
template<typename T>
class CustomStack {
    vector<T> elements;
public:
    void push(T value) { elements.push_back(value); }
    void pop() { if (!elements.empty()) elements.pop_back(); }
    T top() { return elements.back(); }
    bool empty() { return elements.empty(); }
};

// Queue
template<typename T>
class CustomQueue {
    vector<T> elements;
    int frontPointer = 0;
public:
    void push(T value) { elements.push_back(value); }
    void pop() { if (frontPointer < elements.size()) frontPointer++; }
    T front() { return elements[frontPointer]; }
    bool empty() { return frontPointer >= elements.size(); }
};

// Max Priority Queue
template<typename T>
class MaxHeap {
    vector<T> heap;
    void siftUp(int index) {
        while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }
    void siftDown(int index) {
        int n = heap.size();
        while (2 * index + 1 < n) {
            int child = 2 * index + 1;
            if (child + 1 < n && heap[child + 1] > heap[child]) child++;
            if (heap[index] >= heap[child]) break;
            swap(heap[index], heap[child]);
            index = child;
        }
    }
public:
    void push(T value) {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }
    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        siftDown(0);
    }
    T top() { return heap.front(); }
    bool empty() { return heap.empty(); }
};

// Min Priority Queue
template<typename T>
class MinHeap {
    vector<T> heap;
    void siftUp(int index) {
        while (index > 0 && heap[index] < heap[(index - 1) / 2]) {
            swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }
    void siftDown(int index) {
        int n = heap.size();
        while (2 * index + 1 < n) {
            int child = 2 * index + 1;
            if (child + 1 < n && heap[child + 1] < heap[child]) child++;
            if (heap[index] <= heap[child]) break;
            swap(heap[index], heap[child]);
            index = child;
        }
    }
public:
    void push(T value) {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }
    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        siftDown(0);
    }
    T top() { return heap.front(); }
    bool empty() { return heap.empty(); }
};

// Singly Linked List Node
struct ListNode {
    int value;
    ListNode* next;
    ListNode(int val) : value(val), next(nullptr) {}
};

// Binary Tree Node
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Simple Map using vector
class CustomMap {
    vector<pair<int, int>> entries;
public:
    void insert(int key, int value) {
        for (auto& entry : entries) {
            if (entry.first == key) {
                entry.second = value;
                return;
            }
        }
        entries.push_back({key, value});
    }
    int get(int key) {
        for (auto& entry : entries)
            if (entry.first == key) return entry.second;
        return -1;
    }
};

// Unordered Map using vector and hashing
class CustomUnorderedMap {
    static const int SIZE = 100;
    vector<pair<int, int>> buckets[SIZE];

    int hash(int key) { return key % SIZE; }

public:
    void insert(int key, int value) {
        int idx = hash(key);
        for (auto& entry : buckets[idx]) {
            if (entry.first == key) {
                entry.second = value;
                return;
            }
        }
        buckets[idx].push_back({key, value});
    }

    int get(int key) {
        int idx = hash(key);
        for (auto& entry : buckets[idx])
            if (entry.first == key) return entry.second;
        return -1;
    }
};

// Multimap
class CustomMultiMap {
    vector<pair<int, int>> entries;
public:
    void insert(int key, int value) {
        entries.push_back({key, value});
    }
    vector<int> get(int key) {
        vector<int> results;
        for (auto& entry : entries)
            if (entry.first == key) results.push_back(entry.second);
        return results;
    }
};

// Set
class CustomSet {
    vector<int> elements;
public:
    void insert(int value) {
        for (int v : elements)
            if (v == value) return;
        elements.push_back(value);
    }
};

// Ordered Set
class CustomOrderedSet {
    vector<int> elements;
public:
    void insert(int value) {
        if (!contains(value)) {
            elements.push_back(value);
            sort(elements.begin(), elements.end());
        }
    }
    bool contains(int value) {
        for (int v : elements)
            if (v == value) return true;
        return false;
    }
};

// Multiset
class CustomMultiSet {
    vector<int> elements;
public:
    void insert(int value) {
        elements.push_back(value);
    }
};

// Deque
template<typename T>
class CustomDeque {
    vector<T> elements;
    int frontPointer = 0;
public:
    void push_back(T value) { elements.push_back(value); }
    void push_front(T value) { elements.insert(elements.begin() + frontPointer, value); }
    void pop_back() { if (!elements.empty()) elements.pop_back(); }
    void pop_front() { if (frontPointer < elements.size()) frontPointer++; }
    T front() { return elements[frontPointer]; }
    T back() { return elements.back(); }
    bool empty() { return frontPointer >= elements.size(); }
};

// Disjoint Set Union (Union-Find)
class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.assign(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int node) {
        if (parent[node] != node)
            parent[node] = find(parent[node]);
        return parent[node];
    }
    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (rank[u] < rank[v]) parent[u] = v;
            else if (rank[v] < rank[u]) parent[v] = u;
            else {
                parent[v] = u;
                rank[u]++;
            }
        }
    }
};
