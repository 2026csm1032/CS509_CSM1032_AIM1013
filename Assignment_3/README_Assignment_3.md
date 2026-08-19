# Assignment 3 – Gradient Descent and Maxflow-Mincut

## Course

**CS509 – PG Software Lab**

## Assignment Type

**Buddy Assignment (Pair of Two Students)**

## Team Members

| Name | Entry Number |
| ---- | ------------ |
| Rakshit Gautam | 2026CSM1032 |
| Mohd Shah Faaz | 2026AIM1013 |

---

# Objective

Implement the following algorithms:

- Gradient Descent
- Maxflow-Mincut

Gradient Descent operates on one-variable polynomial functions, while Maxflow-Mincut operates on directed graphs.

For Maxflow-Mincut, the input graph is first read as an adjacency list and converted into CSR format before algorithm execution.

As required, **CSR conversion time is not included in the reported execution time**.

---

# Repository Structure

```text
Assignment_3/
│
├── driver/
│   ├── gradient_descent_driver.cpp
│   ├── main_driver.cpp
│   └── maxf_driver.cpp
│
├── output/
│   ├── gd_output_gd_01.txt
│   ├── gd_output_gd_02.txt
│   ├── gd_output_gd_03.txt
│   ├── gd_output_gd_04.txt
│   ├── gd_output_gd_05.txt
│   ├── maxflow_output_maxflow_10.txt
│   ├── maxflow_output_maxflow_100.txt
│   ├── maxflow_output_maxflow_1000.txt
│   ├── maxflow_output_maxflow_10000.txt
│   └── maxflow_output_maxflow_50000.txt
│
├── src/
│   ├── gradient_descent.cpp
│   ├── gradient_descent.h
│   ├── maxf.cpp
│   └── maxf.h
│
└── test/
    ├── gd_01.txt
    ├── gd_02.txt
    ├── gd_03.txt
    ├── gd_04.txt
    ├── gd_05.txt
    ├── maxflow_10.txt
    ├── maxflow_100.txt
    ├── maxflow_1000.txt
    ├── maxflow_10000.txt
    └── maxflow_50000.txt
```

---

# Algorithms

## 1. Gradient Descent

Gradient Descent is an iterative optimization algorithm used to find the minimum of a polynomial function.

For a polynomial:

```text
f(x) = c0 + c1*x + c2*x^2 + ... + cd*x^d
```

the derivative is calculated and `x` is repeatedly updated using the learning rate until the derivative is within the specified tolerance or the maximum number of iterations is reached.

The implementation supports different polynomial degrees using the same generic algorithm.

### Time Complexity

- Depends on the polynomial degree and number of iterations.

### Space Complexity

- **O(d)** for the polynomial coefficients.

---

## 2. Maxflow-Mincut

Maxflow-Mincut determines the maximum amount of flow that can be sent from a source vertex to a sink vertex in a directed graph subject to edge capacities.

The corresponding minimum cut separates the source and sink into two sets. The implementation calculates the maximum flow and obtains the minimum-cut information from the resulting residual graph.

### Time Complexity

- Depends on the max-flow algorithm and graph structure.

### Space Complexity

- **O(V + E)** apart from auxiliary data used by the algorithm.

---

# CSR Representation

For Maxflow-Mincut, the graph is converted from adjacency-list format into CSR.

CSR contains:

- **row_ptr** – starting and ending positions of each vertex's neighbour list
- **col_idx** – neighbouring vertex indices
- **values** – edge capacities

The adjacency-list-to-CSR conversion is preprocessing and **is excluded from execution timing**.

Gradient Descent does not use CSR because it directly reads polynomial coefficients and optimization parameters from its input file.

---

# Input Format

## Gradient Descent

The Gradient Descent test files use the following format:

```text
DEGREE d
COEFFICIENTS c0 c1 c2 ... cd
INITIAL_X x
LEARNING_RATE rate
TOLERANCE tolerance
MAX_ITERATIONS iterations
```

The coefficient values are given in ascending order of powers.

### Test Cases

| Test File | Degree | Initial X | Learning Rate | Tolerance | Max Iterations |
| --------- | -----: | --------: | ------------: | ---------: | -------------: |
| gd_01.txt | 2 | 0 | 0.10 | 1e-6 | 5,000 |
| gd_02.txt | 4 | 2 | 0.02 | 1e-6 | 10,000 |
| gd_03.txt | 6 | 2 | 0.02 | 1e-6 | 20,000 |
| gd_04.txt | 8 | 2 | 0.01 | 1e-8 | 50,000 |
| gd_05.txt | 10 | 2 | 0.005 | 1e-10 | 100,000 |

---

## Maxflow-Mincut

The Maxflow-Mincut test files use the following directed adjacency-list format:

```text
V E
u degree neighbor1 capacity1 neighbor2 capacity2 ...
...
SOURCE s
SINK t
```

Where:

- `V` is the number of vertices.
- `E` is the number of directed edges.
- Each neighbour is followed by its edge capacity.
- The graph is directed.
- `SOURCE` specifies the source vertex.
- `SINK` specifies the sink vertex.

---

# Compilation

Compile using any C++17 compatible compiler.

### Gradient Descent

```bash
g++ driver/gradient_descent_driver.cpp src/gradient_descent.cpp -o gd.exe
```

### Maxflow-Mincut

```bash
g++ driver/maxf_driver.cpp src/maxf.cpp ../Assignment_2/src/csr.cpp -o maxf.exe
```

---

# Execution

The programs can be executed using the corresponding executable and test input.

```bash
./gd.exe
./maxf.exe
```

The common wrapper can also be used through the assignment driver/menu.

---

# Test Files

## Gradient Descent

- `gd_01.txt`
- `gd_02.txt`
- `gd_03.txt`
- `gd_04.txt`
- `gd_05.txt`

## Maxflow-Mincut

- `maxflow_10.txt`
- `maxflow_100.txt`
- `maxflow_1000.txt`
- `maxflow_10000.txt`
- `maxflow_50000.txt`

---

# Result Tables

## 9.2 Gradient Descent Results Table

| File | Degree | x0 | Rate | Tol. | Max Iter. | Exp. x* | Exp. f(x*) | Actual x | Actual f(x) | Iter. / Time | Status |
| ---- | -----: | --: | ---: | ---: | ---------: | ------: | ----------: | --------: | -----------: | ------------ | ------ |
| gd_01.txt | 2 | 0 | 0.10 | 1e-6 | 5,000 | 3 | 0 | 2.999999506349 | 0.000000000000 | 70 / 0.0162 ms | Pass |
| gd_02.txt | 4 | 2 | 0.02 | 1e-6 | 10,000 | 0 | 0 | 0.000000237910 | 0.000000000000 | 180 / 0.0459 ms | Pass |
| gd_03.txt | 6 | 2 | 0.02 | 1e-6 | 20,000 | 0 | 0 | 0.000000483545 | 0.000000000000 | 349 / 0.1101 ms | Pass |
| gd_04.txt | 8 | 2 | 0.01 | 1e-8 | 50,000 | 0 | 0 | 0.000000004975 | 0.000000000000 | 948 / 0.1529 ms | Pass |
| gd_05.txt | 10 | 2 | 0.005 | 1e-10 | 100,000 | 0 | 0 | 0.000000000050 | 0.000000000000 | 2,364 / 1.0947 ms | Pass |

---

## 9.3 Maxflow-Mincut Results Table

| File | V | E | Source | Sink | Exp. Flow | Actual Flow | Cut Capacity | Time | Status |
| ---- | -: | -: | -----: | ---: | --------: | ----------: | -----------: | ----: | ------ |
| maxflow_10.txt | 10 | 16 | 0 | 9 | 20 | 20 | 20 | 0.0438 ms | Pass |
| maxflow_100.txt | 100 | 200 | 0 | 99 | 8 | 8 | 8 | 0.1765 ms | Pass |
| maxflow_1000.txt | 1,000 | 2,000 | 0 | 999 | 8 | 8 | 8 | 0.8454 ms | Pass |
| maxflow_10000.txt | 10,000 | 20,000 | 0 | 9,999 | 8 | 8 | 8 | 6.2764 ms | Pass |
| maxflow_50000.txt | 50,000 | 100,000 | 0 | 49,999 | 8 | 8 | 8 | 46.4544 ms | Pass |

---

# Performance Summary

Gradient Descent is tested with polynomial degrees ranging from 2 to 10. The same generic implementation is used for all five test cases. All five test cases converged successfully.

Maxflow-Mincut execution time increases as the number of vertices in the input graph increases. The maximum-flow value is equal to the minimum-cut capacity for all five test cases.

The reported execution time excludes CSR conversion and other input/output operations.
