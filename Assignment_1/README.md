# Assignment 1 – BFS, DFS and SSSP

## Course
**CS509 – PG Software lab**

## Assignment Type
**Buddy Assignment (Pair of Two Students)**

## Team Members

| Name | Entry Number |
|------|--------------|
| Rakshit Gautam | 2026CSM1032 |
| Mohd Shah Faaz | 2026AIM1013 |

---

# Objective

Implement the following graph algorithms using the **Compressed Sparse Row (CSR)** graph representation:

- Breadth-First Search (BFS)
- Depth-First Search (DFS)
- Single Source Shortest Path (SSSP using Dijkstra's Algorithm)

The input graph is first read as an adjacency list and converted into CSR format before algorithm execution. As required, **CSR conversion time is not included in the reported execution time**.

---

# Repository Structure

```
Assignment_1/
│
├── driver/
│   ├── bfs_driver.cpp
│   ├── dfs_driver.cpp
│   ├── sssp_driver.cpp
│   └── main_driver.cpp
│
├── src/
│   ├── bfs.cpp
│   ├── bfs.h
│   ├── dfs.cpp
│   ├── dfs.h
│   ├── sssp.cpp
│   ├── sssp.h
│   ├── csr.cpp
│   ├── csr.h
│   ├── weighted_csr.cpp
│   └── weighted_csr.h
│
├── tests/
├── outputs/
└── README.md
```

---

# Algorithms

## 1. Breadth First Search (BFS)

BFS explores vertices level by level from a given source vertex using a queue. For unweighted graphs it can also determine the minimum number of edges from the source to every reachable vertex.

### Time Complexity
- **O(V + E)**

### Space Complexity
- **O(V)**

---

## 2. Depth First Search (DFS)

DFS explores one branch completely before backtracking. The implementation performs traversal beginning from the given source vertex.

### Time Complexity
- **O(V + E)**

### Space Complexity
- **O(V)**

---

## 3. Single Source Shortest Path (SSSP)

The implementation uses **Dijkstra's Algorithm** for graphs having **positive edge weights**.

### Time Complexity
- **O((V + E) log V)**

### Space Complexity
- **O(V)**

---

# CSR Representation

The graph is converted from adjacency list format into CSR.

CSR contains:

- **row_ptr** – starting index of every vertex
- **col_idx** – destination vertices
- **values** – edge weights (only for weighted graphs)

The conversion is preprocessing and **is excluded from execution timing**.

---

# Input Formats

## BFS / DFS

```
V E
u degree neighbour1 neighbour2 ...
...
SOURCE s
```

---

## SSSP

```
V E
u degree neighbour1 weight1 neighbour2 weight2 ...
...
SOURCE s
```

Only positive edge weights are allowed.

---

# Compilation

Compile using any C++17 compatible compiler.

### Common_wrapper

```bash
g++ common_wrapper/common_wrapper.cpp -o wrapper
```

---

# Execution

```bash
./wrapper.exe
```

---

# Timing Method

Execution time is measured immediately before calling the algorithm and stopped immediately after completion.

The following operations are **not included** in timing:

- File reading
- Input parsing
- Adjacency list construction
- CSR conversion
- Output printing
- File writing

Execution time is reported in **milliseconds (ms)**.

---

# Test Files

- bfs_100.txt
- bfs_1000.txt
- bfs_10000.txt
- bfs_50000.txt
- bfs_100000.txt

- dfs_10.txt
- dfs_100.txt
- dfs_10000.txt
- dfs_50000.txt
- dfs_100000.txt

- sssp_10.txt
- sssp_100.txt
- sssp_10000.txt
- sssp_50000.txt
- sssp_100000.txt

---

# Result Tables

## BFS

| Mode | Test File | Input Type | Input Size | Expected Output | Actual Output | Algorithm Time (ms) | Status |
|------|-----------|------------|------------|-----------------|---------------|--------------------:|--------|
| Double | bfs_100.txt | Adjacency List → CSR | V=100 | BFS Traversal | Correct | 0.025 | Pass |
| Double | bfs_1000.txt | Adjacency List → CSR | V=1000 | BFS Traversal | Correct | 0.247 | Pass |
| Double | bfs_10000.txt | Adjacency List → CSR | V=10000 | BFS Traversal | Correct | 2.987 | Pass |
| Double | bfs_50000.txt | Adjacency List → CSR | V=50000 | BFS Traversal | Correct | 13.987 | Pass |
| Double | bfs_100000.txt | Adjacency List → CSR | V=100000 | BFS Traversal | Correct | 35.848 | Pass |

## DFS

| Mode | Test File | Input Type | Input Size | Expected Output | Actual Output | Algorithm Time (ms) | Status |
|------|-----------|------------|------------|-----------------|---------------|--------------------:|--------|
| Double | dfs_10.txt | Adjacency List → CSR | V=10 | DFS Traversal | Correct | 0.0062 | Pass |
| Double | dfs_100.txt | Adjacency List → CSR | V=100 | DFS Traversal | Correct | 0.0261 | Pass |
| Double | dfs_10000.txt | Adjacency List → CSR | V=10000 | DFS Traversal | Correct | 3.5314 | Pass |
| Double | dfs_50000.txt | Adjacency List → CSR | V=50000 | DFS Traversal | Correct | 16.3827 | Pass |
| Double | dfs_100000.txt | Adjacency List → CSR | V=100000 | DFS Traversal | Correct | 32.113 | Pass |

## SSSP

| Mode | Test File | Input Type | Input Size | Expected Output | Actual Output | Algorithm Time (ms) | Status |
|------|-----------|------------|------------|-----------------|---------------|--------------------:|--------|
| Double | sssp_10.txt | Weighted Adjacency List → CSR | V=10 | Shortest Distances | Correct | 0.0068 | Pass |
| Double | sssp_100.txt | Weighted Adjacency List → CSR | V=100 | Shortest Distances | Correct | 0.0616 | Pass |
| Double | sssp_10000.txt | Weighted Adjacency List → CSR | V=10000 | Shortest Distances | Correct | 11.4286 | Pass |
| Double | sssp_50000.txt | Weighted Adjacency List → CSR | V=50000 | Shortest Distances | Correct | 126.255 | Pass |
| Double | sssp_100000.txt | Weighted Adjacency List → CSR | V=100000 | Shortest Distances | Correct | 156.474 | Pass |

---

# Assumptions

- Vertex numbering starts from **0**.
- SSSP accepts only positive edge weights.
- Graph input is converted to CSR before execution.
- Traversal order depends on adjacency-list order.

---