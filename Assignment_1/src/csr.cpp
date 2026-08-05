#include "csr.h"

void convertToCSR(vector<vector<int>>& adj,vector<int>& row_ptr,vector<int>& col_idx){
    int n=adj.size();

    row_ptr.clear();
    col_idx.clear();

    row_ptr.push_back(0);

    for(int i=0;i<n;i++){
        for(int v:adj[i]){
            col_idx.push_back(v);
        }
        row_ptr.push_back(col_idx.size());
    }
}