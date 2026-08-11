#include "bc.h"
#include "../../Assignment_1/src/bfs.h"

#include <bits/stdc++.h>
using namespace std;

void betweennessCentrality(
    int V,
    vector<int>& row_ptr,
    vector<int>& col_idx,
    vector<double>& centrality
)
{
    centrality.assign(V, 0.0);

    ofstream fout("bc_bfs_temp.txt");

    for (int source = 0; source < V; source++)
    {
        vector<int> distance;

        bfsCSR(
            row_ptr,
            col_idx,
            source,
            distance,
            fout
        );

        int maxDistance = 0;

        for (int v = 0; v < V; v++)
        {
            if (distance[v] > maxDistance)
                maxDistance = distance[v];
        }

        vector<vector<int>> levels(maxDistance + 1);

        for (int v = 0; v < V; v++)
        {
            if (distance[v] != -1)
                levels[distance[v]].push_back(v);
        }

        vector<double> sigma(V, 0.0);
        sigma[source] = 1.0;

        for (int d = 0; d <= maxDistance; d++)
        {
            for (int u : levels[d])
            {
                for (int i = row_ptr[u]; i < row_ptr[u + 1]; i++)
                {
                    int v = col_idx[i];

                    if (distance[v] == distance[u] + 1)
                        sigma[v] += sigma[u];
                }
            }
        }

        vector<double> delta(V, 0.0);

        for (int d = maxDistance; d >= 0; d--)
        {
            for (int u : levels[d])
            {
                for (int i = row_ptr[u]; i < row_ptr[u + 1]; i++)
                {
                    int v = col_idx[i];

                    if (distance[v] == distance[u] + 1)
                    {
                        if (sigma[v] != 0)
                        {
                            delta[u] +=
                                (sigma[u] / sigma[v]) *
                                (1.0 + delta[v]);
                        }
                    }
                }
            }
        }

        for (int v = 0; v < V; v++)
        {
            if (v != source)
                centrality[v] += delta[v];
        }
    }

    fout.close();

    remove("bc_bfs_temp.txt");
}