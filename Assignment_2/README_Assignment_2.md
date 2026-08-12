# Assignment 2 – Triangle Counting, Betweenness Centrality and Connected Components

## Course

**CS509 – PG Software lab**

## Assignment Type

**Buddy Assignment (Pair of Two Students)**

## Team Members

| Name | Entry Number |
| ---- | ------------ |
| Rakshit Gautam | 2026CSM1032 |
| Mohd Shah Faaz | 2026AIM1013 |

---

# Objective

Implement the following graph algorithms using the **Compressed Sparse Row (CSR)** graph representation:

- Triangle Counting
- Betweenness Centrality
- Connected Components

The input graph is first read as an adjacency list and converted into CSR format before algorithm execution. As required, **CSR conversion time is not included in the reported execution time**.

The algorithms operate on **undirected graphs**.

---

# Repository Structure

```text
Assignment_2/
│
├── driver/
│
├── output/
│
├── src/
│   ├── bc.cpp
│   ├── bc.h
│   ├── cc.cpp
│   ├── cc.h
│   ├── triangle_count.cpp
│   └── triangle_count.h
│
├── tests/
│   ├── bc/
│   ├── cc/
│   └── tc/
│
├── assignment_2.exe
├── bc.exe
├── cc.exe
├── tc.exe
└── README.md
```

---

# Algorithms

## 1. Triangle Counting

Triangle Counting determines the number of sets of three vertices that are pairwise connected by edges in an undirected graph.

For each vertex, pairs of its neighbours are examined and checked for a common connection. Since every triangle is discovered once at each of its three vertices, the raw count is divided by 3 to obtain the final number of triangles.

### Time Complexity

- Depends on the graph representation and common-neighbour checking method.
- Sorted adjacency lists can improve the common-neighbour checks.

### Space Complexity

- **O(V + E)** using CSR representation.

---

## 2. Betweenness Centrality

Betweenness Centrality measures how frequently a vertex occurs on shortest paths between other pairs of vertices.

For the unweighted graphs used in this assignment, **Brandes' algorithm** is used with BFS from every vertex. The implementation reports the **raw (unnormalized)** centrality value for every vertex.

### Time Complexity

- **O(V · E)** for unweighted graphs using Brandes' algorithm.

### Space Complexity

- **O(V + E)** apart from auxiliary data used during each BFS.

---

## 3. Connected Components

Connected Components identifies the maximal sets of vertices in which every pair of vertices is connected by a path.

The implementation performs graph traversal using BFS/graph traversal logic and assigns a component ID to every vertex, including isolated vertices.

### Time Complexity

- **O(V + E)**

### Space Complexity

- **O(V)** apart from the CSR graph representation.

---

# CSR Representation

The graph is converted from adjacency-list format into CSR.

CSR contains:

- **row_ptr** – starting and ending positions of each vertex's neighbour list
- **col_idx** – neighbouring vertex indices
- **values** – edge values where applicable

The adjacency-list-to-CSR conversion is preprocessing and **is excluded from execution timing**.

---

# Input Format

The Triangle Counting, Betweenness Centrality and Connected Components test files use the following unweighted undirected adjacency-list format:

```text
V E
u degree neighbour1 neighbour2 ...
...
```

Where:

- `V` is the number of vertices.
- `E` is the number of undirected edges.
- Every undirected edge appears in the adjacency lists of both endpoint vertices.
- A vertex with no neighbours is represented as `u 0`.
- There is no source vertex because all three algorithms operate on the complete graph.

---

# Compilation

Compile using any C++17 compatible compiler.

### Triangle Counting

```bash
g++ driver.cpp src/triangle_count.cpp ../Assignment_1/src/csr.cpp -o tc.exe
```

### Betweenness Centrality

```bash
g++ driver.cpp src/bc.cpp ../Assignment_1/src/csr.cpp ../Assignment_1/src/bfs.cpp -o bc.exe
```

### Connected Components

```bash
g++ driver.cpp src/cc.cpp ../Assignment_1/src/csr.cpp ../Assignment_1/src/bfs.cpp -o cc.exe
```

---

# Execution

The programs can be executed using the corresponding executable and test input.

```bash
./tc.exe
./bc.exe
./cc.exe
```

The common wrapper can also be used through the assignment driver/menu.

---

# Test Files

## Triangle Counting

- `tc_10.txt`
- `tc_100.txt`
- `tc_10000.txt`
- `tc_50000.txt`
- `tc_100000.txt`

## Betweenness Centrality

- `bc_10.txt`
- `bc_100.txt`
- `bc_1000.txt`
- `bc_5000.txt`
- `bc_10000.txt`

## Connected Components

- `cc_10.txt`
- `cc_100.txt`
- `cc_10000.txt`
- `cc_50000.txt`
- `cc_100000.txt`

---

# Result Tables

## Triangle Counting

| Mode | Test File | Input Type | Input Size | Expected Output | Actual Output | Algorithm Time (ms) | Status |
| ---- | --------- | ---------- | ---------- | --------------- | ------------- | ------------------: | ------ |
| Double | tc_10.txt | Adjacency List → CSR | V=10 | Total Triangles | Correct | 0.0019 | Pass |
| Double | tc_100.txt | Adjacency List → CSR | V=100 | Total Triangles | Correct | 0.0559 | Pass |
| Double | tc_10000.txt | Adjacency List → CSR | V=10000 | Total Triangles | Correct | 1.1486 | Pass |
| Double | tc_50000.txt | Adjacency List → CSR | V=50000 | Total Triangles | Correct | 8.3886 | Pass |
| Double | tc_100000.txt | Adjacency List → CSR | V=100000 | Total Triangles | Correct | 13.9219 | Pass |

## Betweenness Centrality

| Mode | Test File | Input Type | Input Size | Expected Output | Actual Output | Algorithm Time (ms) | Status |
| ---- | --------- | ---------- | ---------- | --------------- | ------------- | ------------------: | ------ |
| Double | bc_10.txt | Adjacency List → CSR | V=10 | Centrality per vertex | Correct | 2.48 | Pass |
| Double | bc_100.txt | Adjacency List → CSR | V=100 | Centrality per vertex | Correct | 37.52 | Pass |
| Double | bc_1000.txt | Adjacency List → CSR | V=1000 | Centrality per vertex | Correct | 703.95 | Pass |
| Double | bc_5000.txt | Adjacency List → CSR | V=5000 | Centrality per vertex | Correct | 15480.62 | Pass |
| Double | bc_10000.txt | Adjacency List → CSR | V=10000 | Centrality per vertex | Correct | 63526.27 | Pass |

## Connected Components

| Mode | Test File | Input Type | Input Size | Expected Output | Actual Output | Algorithm Time (ms) | Status |
| ---- | --------- | ---------- | ---------- | --------------- | ------------- | ------------------: | ------ |
| Double | cc_10.txt | Adjacency List → CSR | V=10 | Components per vertex | Correct | 2.0368 | Pass |
| Double | cc_100.txt | Adjacency List → CSR | V=100 | Components per vertex | Correct | 1.7878 | Pass |
| Double | cc_10000.txt | Adjacency List → CSR | V=10000 | Components per vertex | Correct | 5.473 | Pass |
| Double | cc_50000.txt | Adjacency List → CSR | V=50000 | Components per vertex | Correct | 32.0795 | Pass |
| Double | cc_100000.txt | Adjacency List → CSR | V=100000 | Components per vertex | Correct | 122.519 | Pass |

---

# Performance Summary

Triangle Counting shows low execution time even for the largest tested graph. Connected Components also scales efficiently as the number of vertices increases.

Betweenness Centrality requires significantly more execution time at larger graph sizes. This is expected because Brandes' algorithm performs a BFS-based computation from every vertex, resulting in substantially higher computational work compared with a single graph traversal.

---

