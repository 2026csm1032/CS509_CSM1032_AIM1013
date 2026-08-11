#include <bits/stdc++.h>
#include "../../Assignment_1/src/csr.h"
#include "../src/bc.h"

using namespace std;

void runBC(const string& inputFile, const string& outputFile)
{
    ifstream fin(inputFile);

    if (!fin)
    {
        cerr << "Error: Unable to open " << inputFile << "\n";
        return;
    }

    int V, E;

    if (!(fin >> V >> E))
    {
        cerr << "Error: Invalid header in " << inputFile << "\n";
        return;
    }

    cout << "\nProcessing: " << inputFile << "\n";
    cout << "Vertices: " << V << ", Edges: " << E << "\n";

    if (V <= 0 || V > 100000)
    {
        cerr << "Error: Invalid number of vertices: " << V << "\n";
        return;
    }

    vector<vector<int>> adj(V);

    for (int i = 0; i < V; i++)
    {
        int u, degree;

        if (!(fin >> u >> degree))
        {
            cerr << "Error: Invalid vertex data at line " << i + 2 << "\n";
            return;
        }

        if (u < 0 || u >= V)
        {
            cerr << "Error: Invalid vertex number: " << u << "\n";
            return;
        }

        if (degree < 0 || degree > V)
        {
            cerr << "Error: Invalid degree for vertex "
                 << u << ": " << degree << "\n";
            return;
        }

        for (int j = 0; j < degree; j++)
        {
            int v;

            if (!(fin >> v))
            {
                cerr << "Error: Missing neighbor for vertex "
                     << u << "\n";
                return;
            }

            if (v < 0 || v >= V)
            {
                cerr << "Error: Invalid neighbor "
                     << v << " for vertex " << u << "\n";
                return;
            }

            adj[u].push_back(v);
        }
    }

    fin.close();

    vector<int> row_ptr;
    vector<int> col_idx;

    convertToCSR(adj, row_ptr, col_idx);

    vector<double> centrality;

    auto start = chrono::high_resolution_clock::now();

    betweennessCentrality(
        V,
        row_ptr,
        col_idx,
        centrality
    );

    auto end = chrono::high_resolution_clock::now();

    double executionTime =
        chrono::duration<double, milli>(end - start).count();

    ofstream fout(outputFile);

    if (!fout)
    {
        cerr << "Error: Unable to create " << outputFile << "\n";
        return;
    }

    fout << "Algorithm: Betweenness Centrality\n";
    fout << "Vertex Centrality\n";

    fout << fixed << setprecision(2);

    for (int i = 0; i < V; i++)
    {
        fout << i << " " << centrality[i] << "\n";
    }

    fout << "Execution time: "
         << executionTime
         << " ms\n";

    fout.close();

    cout << "Execution time: "
         << executionTime
         << " ms\n";
}

int main()
{
    vector<string> inputFiles =
    {
        "tests/bc/bc_10.txt",
        "tests/bc/bc_100.txt",
        "tests/bc/bc_1000.txt",
        "tests/bc/bc_5000.txt",
        "tests/bc/bc_10000.txt"
    };

    vector<string> outputFiles =
    {
        "output/bc_10.txt",
        "output/bc_100.txt",
        "output/bc_1000.txt",
        "output/bc_5000.txt",
        "output/bc_10000.txt"
    };

    int choice;

    while (true)
    {
        cout << "\n========== Betweenness Centrality ==========\n";
        cout << "1. bc_10.txt\n";
        cout << "2. bc_100.txt\n";
        cout << "3. bc_1000.txt\n";
        cout << "4. bc_5000.txt\n";
        cout << "5. bc_10000.txt\n";
        cout << "6. Run All\n";
        cout << "0. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        if (choice == 0)
            break;

        if (choice >= 1 && choice <= 5)
        {
            runBC(
                inputFiles[choice - 1],
                outputFiles[choice - 1]
            );
        }
        else if (choice == 6)
        {
            cout << "\nExecution Times:\n";

            for (int i = 0; i < 5; i++)
            {
                runBC(
                    inputFiles[i],
                    outputFiles[i]
                );
            }
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}