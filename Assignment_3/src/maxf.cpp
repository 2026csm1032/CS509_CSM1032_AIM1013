#include "maxf.h"

#include <queue>
#include <limits>

using namespace std;

struct ResidualEdge
{
    int to;
    int rev;
    int capacity;
};

class Dinic
{
private:
    int V;
    vector<vector<ResidualEdge>> graph;
    vector<int> level;
    vector<int> ptr;

    bool bfs(int source, int sink)
    {
        fill(level.begin(), level.end(), -1);

        queue<int> q;
        q.push(source);
        level[source] = 0;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (const auto& edge : graph[u])
            {
                if (edge.capacity > 0 && level[edge.to] == -1)
                {
                    level[edge.to] = level[u] + 1;
                    q.push(edge.to);
                }
            }
        }

        return level[sink] != -1;
    }

    int dfs(int u, int sink, int pushed)
    {
        if (pushed == 0)
            return 0;

        if (u == sink)
            return pushed;

        while (ptr[u] < (int)graph[u].size())
        {
            ResidualEdge& edge = graph[u][ptr[u]];

            if (edge.capacity > 0 &&
                level[edge.to] == level[u] + 1)
            {
                int flow = dfs(
                    edge.to,
                    sink,
                    min(pushed, edge.capacity)
                );

                if (flow > 0)
                {
                    edge.capacity -= flow;
                    graph[edge.to][edge.rev].capacity += flow;
                    return flow;
                }
            }

            ptr[u]++;
        }

        return 0;
    }

public:
    Dinic(int vertices)
    {
        V = vertices;
        graph.resize(V);
        level.resize(V);
        ptr.resize(V);
    }

    void addEdge(int u, int v, int capacity)
    {
        ResidualEdge forward;
        forward.to = v;
        forward.rev = graph[v].size();
        forward.capacity = capacity;

        ResidualEdge reverse;
        reverse.to = u;
        reverse.rev = graph[u].size();
        reverse.capacity = 0;

        graph[u].push_back(forward);
        graph[v].push_back(reverse);
    }

    long long maxFlow(int source, int sink)
    {
        long long flow = 0;

        while (bfs(source, sink))
        {
            fill(ptr.begin(), ptr.end(), 0);

            while (true)
            {
                int pushed = dfs(
                    source,
                    sink,
                    numeric_limits<int>::max()
                );

                if (pushed == 0)
                    break;

                flow += pushed;
            }
        }

        return flow;
    }

    const vector<vector<ResidualEdge>>& getGraph() const
    {
        return graph;
    }
};

MaxFlowResult maxflow(
    int V,
    const vector<int>& row_ptr,
    const vector<int>& col_idx,
    const vector<int>& values,
    int source,
    int sink
)
{
    Dinic dinic(V);

    vector<FlowEdge> originalEdges;

    for (int u = 0; u < V; u++)
    {
        for (int i = row_ptr[u]; i < row_ptr[u + 1]; i++)
        {
            int v = col_idx[i];
            int capacity = values[i];

            dinic.addEdge(u, v, capacity);

            originalEdges.push_back({u, v, capacity});
        }
    }

    long long maximumFlow = dinic.maxFlow(source, sink);

    const auto& residualGraph = dinic.getGraph();

    vector<bool> visited(V, false);
    queue<int> q;

    visited[source] = true;
    q.push(source);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (const auto& edge : residualGraph[u])
        {
            if (edge.capacity > 0 && !visited[edge.to])
            {
                visited[edge.to] = true;
                q.push(edge.to);
            }
        }
    }

    vector<int> sourceSide;
    vector<int> sinkSide;

    for (int i = 0; i < V; i++)
    {
        if (visited[i])
            sourceSide.push_back(i);
        else
            sinkSide.push_back(i);
    }

    vector<FlowEdge> cutEdges;
    long long minCutCapacity = 0;

    for (const auto& edge : originalEdges)
    {
        if (visited[edge.u] && !visited[edge.v])
        {
            cutEdges.push_back(edge);
            minCutCapacity += edge.capacity;
        }
    }

    MaxFlowResult result;

    result.maxFlow = maximumFlow;
    result.minCutCapacity = minCutCapacity;
    result.sourceSide = sourceSide;
    result.sinkSide = sinkSide;
    result.cutEdges = cutEdges;

    return result;
}