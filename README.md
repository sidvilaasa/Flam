# Android Assignment – Set 1

This repository contains solutions to selected questions from the Android Assignment – Set 1. The questions focus on core algorithm/data structure implementation and a simple Android app using MVVM architecture.

---

## Questions Attempted

### Q1: LRU Cache (Least Recently Used)

**Problem**:  
Design and implement a cache system that stores key-value pairs with a fixed capacity. If the cache exceeds the capacity, it removes the least recently used item.

**Constraints**:
- All operations (`get`, `put`) must be performed in **O(1)** time.
- Capacity: 1 to 3000.

**Tech**: C++ implementation using `unordered_map` + doubly linked list.

---

### Q2: Custom HashMap

**Problem**:  
Implement a simplified version of a HashMap without using any built-in dictionary or map libraries. Support three operations:
- `put(key, value)`
- `get(key)`
- `remove(key)`

**Constraints**:
- Keys and values are integers in the range `[0, 10^6]`.
- Average-case O(1) time complexity for all operations.

**Tech**: C++ implementation using a manually designed hash function and separate chaining.



