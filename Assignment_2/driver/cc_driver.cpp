#include <bits/stdc++.h>
#include "../../Assignment_1/src/csr.h"
#include "cc.h"

using namespace std;

void runCC(const string& inputFile, const string& outputFile)
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

    vector<vector<int>> adj(V);

    for (int i = 0; i < V; i++)
    {
        int u, degree;

        fin >> u >> degree;

        for (int j = 0; j < degree; j++)
        {
            int v;
            fin >> v;
            adj[u].push_back(v);
        }
    }

    fin.close();

    vector<int> row_ptr;
    vector<int> col_idx;

    convertToCSR(adj, row_ptr, col_idx);

    vector<int> component;

    auto start = chrono::high_resolution_clock::now();

    connectedComponents(
        V,
        row_ptr,
        col_idx,
        component
    );

    auto end = chrono::high_resolution_clock::now();

    double executionTime =
        chrono::duration<double, milli>(end - start).count();

    int numberOfComponents = 0;

    for (int v = 0; v < V; v++)
    {
        if (component[v] + 1 > numberOfComponents)
            numberOfComponents = component[v] + 1;
    }

    ofstream fout(outputFile);

    if (!fout)
    {
        cerr << "Error: Unable to create " << outputFile << "\n";
        return;
    }

    fout << "Algorithm: Connected Components\n";
    fout << "Number of components: "
         << numberOfComponents << "\n";
    fout << "Vertex Component\n";

    for (int i = 0; i < V; i++)
    {
        fout << i << " "
             << component[i] << "\n";
    }

    fout << "Execution time: "
         << executionTime
         << " ms\n";

    fout.close();

    cout << inputFile
         << " : "
         << executionTime
         << " ms\n";
}

int main()
{
    vector<string> inputFiles =
    {
        "input/cc_10.txt",
        "input/cc_100.txt",
        "input/cc_10000.txt",
        "input/cc_50000.txt",
        "input/cc_100000.txt"
    };

    vector<string> outputFiles =
    {
        "output/cc_10.txt",
        "output/cc_100.txt",
        "output/cc_10000.txt",
        "output/cc_50000.txt",
        "output/cc_100000.txt"
    };

    int choice;

    while (true)
    {
        cout << "\n========== Connected Components ==========\n";
        cout << "1. cc_10.txt\n";
        cout << "2. cc_100.txt\n";
        cout << "3. cc_10000.txt\n";
        cout << "4. cc_50000.txt\n";
        cout << "5. cc_100000.txt\n";
        cout << "6. Run All\n";
        cout << "0. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        if (choice == 0)
            break;

        if (choice >= 1 && choice <= 5)
        {
            runCC(
                inputFiles[choice - 1],
                outputFiles[choice - 1]
            );
        }
        else if (choice == 6)
        {
            cout << "\nExecution Times:\n";

            for (int i = 0; i < 5; i++)
            {
                runCC(
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