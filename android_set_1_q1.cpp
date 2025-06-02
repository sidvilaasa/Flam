#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    struct Node {
        int key, value;
        Node *prev, *next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache;
    Node *head, *tail;

    void remove(Node* node) {
        cache.erase(node->key);
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }

    void moveToFront(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void insertNew(Node* node) {
        cache[node->key] = node;
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int cap) : capacity(cap) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;
        Node* node = cache[key];
        moveToFront(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* existing = cache[key];
            existing->value = value;
            moveToFront(existing);
        } else {
            if (cache.size() == capacity) {
                Node* lru = tail->prev;
                remove(lru);
            }
            Node* node = new Node(key, value);
            insertNew(node);
        }
    }
};

int main() {
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    cout << lru.get(1) << endl;
    lru.put(3, 3);
    cout << lru.get(2) << endl;
    lru.put(4, 4);
    cout << lru.get(1) << endl;
    cout << lru.get(3) << endl;
    cout << lru.get(4) << endl; 
}
