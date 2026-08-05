#include<bits/stdc++.h>
#include "../src/csr.h"
#include "../src/dfs.h"

using namespace std;

int main(int argc,char* argv[]){

    if(argc!=2){
        cout<<"Usage: dfs test_file\n";
        return 0;
    }

    string filePath="./tests/dfs/";
    filePath+=argv[1];

    ifstream fin(filePath);

    if(!fin){
        cout<<"Input file not found\n";
        return 0;
    }

    int V,E;
    fin>>V>>E;

    vector<vector<int>> adj(V);

    for(int i=0;i<V;i++){

        int u,degree;
        fin>>u>>degree;

        for(int j=0;j<degree;j++){

            int v;
            fin>>v;

            adj[u].push_back(v);
        }
    }

    string temp;
    int source;

    fin>>temp>>source;

    fin.close();

    vector<int> row_ptr;
    vector<int> col_idx;

    convertToCSR(adj,row_ptr,col_idx);

    string outputFile="./outputs/dfs_output_"+string(argv[1]);

    ofstream fout(outputFile);

    if(!fout){
        cout<<"Unable to create output file\n";
        return 0;
    }

    fout<<"Algorithm: DFS\n";
    fout<<"Source: "<<source<<"\n\n";

    auto start=chrono::high_resolution_clock::now();

    dfsCSR(row_ptr,col_idx,source,fout);

    auto end=chrono::high_resolution_clock::now();

    double executionTime=chrono::duration<double,milli>(end-start).count();

    fout<<"Execution Time: "<<executionTime<<" ms\n";

    fout.close();

    cout<<"Output written to: "<<outputFile<<"\n";

    return 0;
}