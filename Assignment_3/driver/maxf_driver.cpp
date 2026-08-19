#include "../src/maxf.h"
#include "../../Assignment_1/src/csr.h"

#include<bits/stdc++.h>

using namespace std;

bool runMaxflow(
    const string& inputFile,
    const string& outputFile
)
{
    ifstream input(inputFile);

    if (!input.is_open())
    {
        cout << "Error: Cannot open input file: "
             << inputFile << endl;

        return false;
    }

    int V, E;

    input >> V >> E;

    vector<vector<int>> adjList(V);
    vector<vector<int>> capacityList(V);

    for (int i = 0; i < V; i++)
    {
        int u;
        int degree;

        input >> u >> degree;

        for (int j = 0; j < degree; j++)
        {
            int v;
            int capacity;

            input >> v >> capacity;

            adjList[u].push_back(v);
            capacityList[u].push_back(capacity);
        }
    }

    string sourceLabel;
    string sinkLabel;

    int source;
    int sink;

    input >> sourceLabel >> source;
    input >> sinkLabel >> sink;

    input.close();

    vector<int> row_ptr;
    vector<int> col_idx;
    vector<int> values;

    convertToCSR(
        adjList,
        row_ptr,
        col_idx
    );

    values.reserve(col_idx.size());

    for (int u = 0; u < V; u++)
    {
        for (int j = 0; j < (int)capacityList[u].size(); j++)
        {
            values.push_back(capacityList[u][j]);
        }
    }

    auto start =
        chrono::high_resolution_clock::now();

    MaxFlowResult result = maxflow(
        V,
        row_ptr,
        col_idx,
        values,
        source,
        sink
    );

    auto end =
        chrono::high_resolution_clock::now();

    double executionTime =
        chrono::duration<double, milli>(
            end - start
        ).count();

    ofstream output(outputFile);

    if (!output.is_open())
    {
        cout << "Error: Cannot create output file: "
             << outputFile << endl;

        return false;
    }

    output << "========== Maxflow-Mincut ==========\n\n";

    output << "Vertices: "
           << V << endl;

    output << "Edges: "
           << E << endl;

    output << "Source: "
           << source << endl;

    output << "Sink: "
           << sink << endl;

    output << "\nMaximum Flow: "
           << result.maxFlow << endl;

    output << "Minimum Cut Capacity: "
           << result.minCutCapacity << endl;

    output << "\nSource Side:\n";

    for (int vertex : result.sourceSide)
    {
        output << vertex << " ";
    }

    output << "\n";

    output << "\nSink Side:\n";

    for (int vertex : result.sinkSide)
    {
        output << vertex << " ";
    }

    output << "\n";

    output << "\nCut Edges:\n";

    for (const auto& edge : result.cutEdges)
    {
        output << edge.u
               << " -> "
               << edge.v
               << " : "
               << edge.capacity
               << endl;
    }

    output << "\nExecution Time: "
           << executionTime
           << " ms"
           << endl;

    output.close();

    cout << "Execution time: "
         << executionTime
         << " ms"
         << endl;

    cout << "Output file: "
         << outputFile
         << endl;

    return true;
}


void maxflowMenu()
{
    vector<string> inputFiles =
    {
        "test/maxflow_10.txt",
        "test/maxflow_100.txt",
        "test/maxflow_1000.txt",
        "test/maxflow_10000.txt",
        "test/maxflow_50000.txt"
    };

    vector<string> outputFiles =
    {
        "output/maxflow_10.txt",
        "output/maxflow_100.txt",
        "output/maxflow_1000.txt",
        "output/maxflow_10000.txt",
        "output/maxflow_50000.txt"
    };

    int choice;

    while (true)
    {
        cout << "\n========== Maxflow-Mincut ==========\n";

        cout << "1. maxflow_10.txt\n";
        cout << "2. maxflow_100.txt\n";
        cout << "3. maxflow_1000.txt\n";
        cout << "4. maxflow_10000.txt\n";
        cout << "5. maxflow_50000.txt\n";
        cout << "6. Run All\n";
        cout << "0. Exit\n";

        cout << "\nEnter Choice : ";
        cin >> choice;

        if (choice == 0)
        {
            cout << "Exiting...\n";
            return;
        }

        if (choice >= 1 && choice <= 5)
        {
            int index = choice - 1;

            cout << "\nRunning "
                 << inputFiles[index]
                 << " ...\n";

            runMaxflow(
                inputFiles[index],
                outputFiles[index]
            );
        }
        else if (choice == 6)
        {
            cout << "\n========== Running All Tests ==========\n";

            for (int i = 0; i < 5; i++)
            {
                cout << "\nRunning "
                     << inputFiles[i]
                     << " ...\n";

                runMaxflow(
                    inputFiles[i],
                    outputFiles[i]
                );
            }

            cout << "\n========== All Tests Completed ==========\n";
        }
        else
        {
            cout << "Invalid Choice\n";
        }
    }
}


int main()
{
    maxflowMenu();

    return 0;
}