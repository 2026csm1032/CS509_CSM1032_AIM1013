#include "dfs.h"

void dfsCSR(vector<int>& row_ptr,vector<int>& col_idx,int source,ofstream& fout){

    int n=row_ptr.size()-1;

    vector<int> vis(n,0);

    stack<int> st;
    st.push(source);

    fout<<"Traversal:\n";

    while(!st.empty()){

        int u=st.top();
        st.pop();

        if(vis[u]){
            continue;
        }

        vis[u]=1;
        fout<<u<<" ";

        for(int i=row_ptr[u+1]-1;i>=row_ptr[u];i--){
            int v=col_idx[i];
            if(!vis[v]){
                st.push(v);
            }
        }
    }

    fout<<"\n\n";
}