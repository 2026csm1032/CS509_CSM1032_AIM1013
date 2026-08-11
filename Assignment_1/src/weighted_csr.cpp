#include "weighted_csr.h"

void convertToWeightedCSR(vector<vector<pair<int,int>>>& adj,vector<int>& row_ptr,vector<int>& col_idx,vector<int>& weights){

    int n=adj.size();

    row_ptr.clear();
    col_idx.clear();
    weights.clear();

    row_ptr.push_back(0);

    for(int i=0;i<n;i++){
        for(auto edge:adj[i]){
            col_idx.push_back(edge.first);
            weights.push_back(edge.second);
        }
        row_ptr.push_back(col_idx.size());
    }
}