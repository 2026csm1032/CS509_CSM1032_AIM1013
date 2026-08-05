#include<bits/stdc++.h>
#include "../src/weighted_csr.h"
#include "../src/sssp.h"

using namespace std;

void writeResultToFile(ofstream& fout,int source,vector<long long>& distance,double executionTime){

    fout<<"Algorithm: SSSP\n";
    fout<<"Source: "<<source<<"\n\n";

    fout<<"Vertex Distance\n";

    for(int i=0;i<distance.size();i++){
        fout<<i<<" ";
        if(distance[i]==LLONG_MAX){
            fout<<"INF";
        }
        else{
            fout<<distance[i];
        }
         fout<<"\n";
    }

    fout<<"\nExecution Time: "<<executionTime<<" ms\n";
}

int main(int argc,char* argv[]){

    if(argc!=2){
        cout<<"Usage: sssp test_file\n";
        return 0;
    }

    string filePath="./tests/sssp/";
    filePath+=argv[1];

    ifstream fin(filePath);

    if(!fin){
        cout<<"Input file not found\n";
        return 0;
    }

    int V,E;
    fin>>V>>E;

    vector<vector<pair<int,int>>> adj(V);

    for(int i=0;i<V;i++){

        int u,degree;
        fin>>u>>degree;

        for(int j=0;j<degree;j++){

            int v,w;
            fin>>v>>w;

            adj[u].push_back({v,w});
        }
    }

    string temp;
    int source;

    fin>>temp>>source;

    fin.close();

    vector<int> row_ptr;
    vector<int> col_idx;
    vector<int> weights;

    convertToWeightedCSR(adj,row_ptr,col_idx,weights);

    vector<long long> distance;

    auto start=chrono::high_resolution_clock::now();

    dijkstraCSR(row_ptr,col_idx,weights,source,distance);

    auto end=chrono::high_resolution_clock::now();

    double executionTime=chrono::duration<double,milli>(end-start).count();

    string outputFile="./outputs/sssp_output_"+string(argv[1]);

    ofstream fout(outputFile);

    if(!fout){
        cout<<"Unable to create output file\n";
        return 0;
    }

    writeResultToFile(fout,source,distance,executionTime);

    fout.close();

    cout<<"Output written to: "<<outputFile<<"\n";

    return 0;
}