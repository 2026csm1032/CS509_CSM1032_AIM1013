#include "triangle_count.h"

long long triangleCountCSR(int V,vector<int>& row_ptr,vector<int>& col_idx){

    long long triangles=0;

    for(int u=0;u<V;u++){

        for(int i=row_ptr[u];
            i<row_ptr[u+1];
            i++){

            int v=col_idx[i];

            if(v<=u){
                continue;
            }

            int p1=row_ptr[u];
            int p2=row_ptr[v];

            while(p1<row_ptr[u+1] &&
                  p2<row_ptr[v+1]){

                if(col_idx[p1]==col_idx[p2]){

                    triangles++;
                    p1++;
                    p2++;
                }

                else if(col_idx[p1]<col_idx[p2]){

                    p1++;
                }

                else{

                    p2++;
                }
            }
        }
    }

    return triangles/3;
}