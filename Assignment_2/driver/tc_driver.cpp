#include<bits/stdc++.h>
#include "../src/triangle_count.h"
#include "../../Assignment_1/src/csr.h"
using namespace std;

void writeResultToFile(ofstream& fout,long long triangles,double executionTime){

    fout<<"Algorithm: Triangle Counting\n\n";

    fout<<"Number Of Triangles: "
        <<triangles
        <<"\n\n";

    fout<<"Execution Time: "
        <<executionTime
        <<" ms\n";
}

int main(int argc,char* argv[]){

    if(argc!=2){
        cout<<"Usage: ./triangle_count input_file\n";
        return 0;
    }

    string filePath="./tests/tc/";
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

    for(int i=0;i<V;i++){
        sort(adj[i].begin(),adj[i].end());
    }

    vector<int> row_ptr;
    vector<int> col_idx;

    convertToCSR(adj,row_ptr,col_idx);

    auto start=chrono::high_resolution_clock::now();

    long long triangles=triangleCountCSR(V,row_ptr,col_idx);

    auto end=chrono::high_resolution_clock::now();

    double executionTime=chrono::duration<double,milli>(end-start).count();

    string outputFile="./output/triangle_count_output_"+string(argv[1]);

    ofstream fout(outputFile);

    if(!fout){
        cout<<"Unable to create output file\n";
        return 0;
    }

    writeResultToFile(fout,triangles,executionTime);

    fout.close();

    cout<<"Output written to: "<<outputFile<<"\n";

    return 0;
}