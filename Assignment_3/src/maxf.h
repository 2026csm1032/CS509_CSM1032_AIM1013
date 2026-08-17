#ifndef MAXFLOW_H
#define MAXFLOW_H

#include <vector>

using namespace std;

struct FlowEdge
{
    int u;
    int v;
    int capacity;
};

struct MaxFlowResult
{
    long long maxFlow;
    long long minCutCapacity;
    vector<int> sourceSide;
    vector<int> sinkSide;
    vector<FlowEdge> cutEdges;
};

MaxFlowResult maxflow(
    int V,
    const vector<int>& row_ptr,
    const vector<int>& col_idx,
    const vector<int>& values,
    int source,
    int sink
);

#endif