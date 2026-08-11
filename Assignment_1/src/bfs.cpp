#include "bfs.h"

void bfsCSR(vector<int>& row_ptr,vector<int>& col_idx,int source,vector<int>& distance,ofstream& fout){

    int n=row_ptr.size()-1;

    distance.assign(n,-1);

    queue<int> q;

    q.push(source);
    distance[source]=0;

    fout<<"Traversal:\n";

    while(!q.empty()){
        int u=q.front();
        q.pop();

        fout<<u<<" ";

        for(int i=row_ptr[u];i<row_ptr[u+1];i++){
            int v=col_idx[i];
            if(distance[v]==-1){
                distance[v]=distance[u]+1;
                q.push(v);
            }
        }
    }

    fout<<"\n\n";
}