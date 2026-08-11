#include "sssp.h"

void dijkstraCSR(vector<int>& row_ptr,vector<int>& col_idx,vector<int>& weights,int source,vector<long long>& distance){

    int n=row_ptr.size()-1;

    distance.assign(n,LLONG_MAX);

    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;

    distance[source]=0;

    pq.push({0,source});

    while(!pq.empty()){

        auto cur=pq.top();
        pq.pop();

        long long dist=cur.first;
        int u=cur.second;

        if(dist!=distance[u]){
            continue;
        }

        for(int i=row_ptr[u];i<row_ptr[u+1];i++){

            int v=col_idx[i];
            int wt=weights[i];

            if(distance[u]+wt<distance[v]){

                distance[v]=distance[u]+wt;

                pq.push({
                    distance[v],
                    v
                });
            }
        }
    }
}