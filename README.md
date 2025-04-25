# Leetcode-2699.-Modify-Graph-Edge-Weights
# 🚀 Modified Graph Edges to Reach Target - LeetCode Solution

This repository contains a C++ solution to the problem where you're asked to **modify the weights of certain edges in a graph (with -1 weight initially)** in order to make the **shortest path from a source node to a destination node equal to a target value**.

---

## 📌 Problem Statement
Given a weighted undirected graph represented by `n` nodes and a list of edges, where some edge weights are initially `-1`, your task is to assign positive integers to those `-1` weights in such a way that:

- The shortest path from the `source` node to the `destination` node is exactly `target`.
- If no such assignment exists, return an empty list.
- If such an assignment exists, return the updated list of edges.

---

## 🧠 Approach

### 1. **Initial Dijkstra Check**
Use Dijkstra's algorithm to find the shortest path from `source` to `destination`:
- If the shortest path is already less than `target`, it's **impossible** to increase it without decreasing the number of edges.
- If the shortest path equals the target, replace all `-1` weights with a very large value to ensure they don't affect the shortest path.

### 2. **Try Edge Adjustments**
If the shortest path is greater than the target:
- Iterate over the edges with weight `-1`.
- Try assigning a weight of `1` temporarily.
- Rerun Dijkstra’s algorithm and check the result:
  - If the shortest path is now less than or equal to the target, adjust that edge's weight to bridge the difference.

### 3. **Edge Replacement**
All remaining `-1` edges are set to a large value (`2e9`) to ensure they don't unintentionally affect the shortest path.

---

## 🛠️ Code Features
- Efficient use of **Dijkstra's algorithm** using a **priority queue**.
- Carefully handles path adjustments with **only one edge weight change**.
- Smart use of a **placeholder large value** for unimportant or risky edge paths.

---

## 🧩 Example
```cpp
Input:
n = 5
target = 9
edges = {{0,1,4}, {1,2,-1}, {2,3,2}, {3,4,3}, {0,4,-1}}
source = 0
destination = 4

Output:
{{0,1,4}, {1,2,2}, {2,3,2}, {3,4,3}, {0,4,2}}
```

---

## ⏱️ Time Complexity
- **Dijkstra's Algorithm:** `O(E * log V)`
- **Outer Loop for Edge Adjustment:** `O(E)` calls to Dijkstra
- **Total Complexity:** `O(E^2 * log V)` in worst case

---

## 📚 Concepts Used
- Graphs
- Dijkstra's Algorithm
- Greedy Adjustment
- Priority Queue (Min Heap)
- Edge Weight Tuning

---

## ✅ When to Use This?
- When modifying edge weights to meet exact path conditions.
- When edge weights are partially known or unknown.
- For advanced graph optimization problems in interviews or competitions.

---

## 📄 License
Feel free to use this code in your own projects or learning materials. Attribution appreciated!

---

Happy Coding 💻✨

---

