#ifndef CC_H
#define CC_H

#include <bits/stdc++.h>
using namespace std;

void connectedComponents(
    int V,
    vector<int>& row_ptr,
    vector<int>& col_idx,
    vector<int>& component
);

#endif