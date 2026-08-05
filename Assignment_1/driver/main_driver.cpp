#include<bits/stdc++.h>
using namespace std;

bool fileExists(string fileName){
    ifstream fin(fileName);
    return fin.good();
}

void compileIfNeeded(string executable,string compileCommand){

    if(fileExists(executable)){
        return;
    }

    cout<<"\nCompiling "<<executable<<"...\n";

    int status=system(compileCommand.c_str());

    if(status!=0){
        cout<<"Compilation Failed\n";
        return;
    }

    cout<<"Compilation Successful\n";
}

void showTests(vector<string>& tests,string executable){

    while(true){

        cout<<"\nAvailable Test Files\n\n";

        for(int i=0;i<tests.size();i++){
            cout<<i+1<<". "<<tests[i]<<"\n";
        }

        cout<<tests.size()+1<<". Run All Tests\n";
        cout<<"0. Back\n\n";

        int choice;
        cout<<"Enter Choice: ";
        cin>>choice;

        if(choice==0){
            return;
        }

        if(choice==tests.size()+1){

            for(auto file:tests){

                cout<<"\n====================================\n";
                cout<<"Running "<<file<<"\n";
                cout<<"====================================\n";

                string command=executable+" "+file;
                system(command.c_str());
                cout<<"\n";
            }
            continue;
        }

        if(choice<1 || choice>tests.size()){
            cout<<"Invalid Choice\n";
            continue;
        }

        string command=executable+" "+tests[choice-1];
        system(command.c_str());
    }
}

int main(){

    vector<string> bfsTests={
        "bfs_100.txt",
        "bfs_1000.txt",
        "bfs_10000.txt",
        "bfs_50000.txt",
        "bfs_100000.txt"
    };

    vector<string> dfsTests={
       "dfs_10.txt",
        "dfs_100.txt",
        "dfs_10000.txt",
        "dfs_50000.txt",
        "dfs_100000.txt"
    };

    vector<string> ssspTests={
        "sssp_10.txt",
        "sssp_100.txt",
        "sssp_10000.txt",
        "sssp_50000.txt",
        "sssp_100000.txt"
    };

    while(true){

        cout<<"\n";
        cout<<"========== ASSIGNMENT 1 ==========\n";
        cout<<"1. BFS\n";
        cout<<"2. DFS\n";
        cout<<"3. SSSP\n";
        cout<<"0. Exit\n\n";

        int choice;
        cout<<"Enter Choice: ";
        cin>>choice;

        if(choice==0){
            break;
        }

        if(choice==1){

            compileIfNeeded("bfs.exe","g++ ""driver/bfs_driver.cpp ""src/bfs.cpp ""src/csr.cpp ""-o bfs.exe");

            showTests(bfsTests,".\\bfs.exe");
        }

        else if(choice==2){

            compileIfNeeded("dfs.exe","g++ ""driver/dfs_driver.cpp ""src/dfs.cpp ""src/csr.cpp ""-o dfs.exe");

            showTests(dfsTests,".\\dfs.exe");
        }

        else if(choice==3){

            compileIfNeeded("sssp.exe","g++ ""driver/sssp_driver.cpp ""src/sssp.cpp ""src/weighted_csr.cpp ""-o sssp.exe");

            showTests(ssspTests,".\\sssp.exe");
        }

        else{
            cout<<"Invalid Choice\n";
        }
    }

    return 0;
}