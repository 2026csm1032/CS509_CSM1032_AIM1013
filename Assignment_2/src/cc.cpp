#include "cc.h"
#include "../../Assignment_1/src/bfs.h"

void connectedComponents(
    int V,
    vector<int>& row_ptr,
    vector<int>& col_idx,
    vector<int>& component
)
{
    component.assign(V, -1);

    ofstream fout("cc_bfs_temp.txt");

    int componentId = 0;

    for (int source = 0; source < V; source++)
    {
        if (component[source] != -1)
            continue;

        vector<int> distance;

        bfsCSR(
            row_ptr,
            col_idx,
            source,
            distance,
            fout
        );

        for (int v = 0; v < V; v++)
        {
            if (distance[v] != -1 && component[v] == -1)
            {
                component[v] = componentId;
            }
        }

        componentId++;
    }

    fout.close();

    remove("cc_bfs_temp.txt");
}