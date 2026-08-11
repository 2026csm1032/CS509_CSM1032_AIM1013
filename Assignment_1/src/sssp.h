#ifndef SSSP_H
#define SSSP_H

#include<bits/stdc++.h>
using namespace std;

void dijkstraCSR(vector<int>& row_ptr,vector<int>& col_idx,vector<int>& weights,int source,vector<long long>& distance);

#endif