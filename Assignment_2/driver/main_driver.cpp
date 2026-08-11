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

    vector<string> tcTests={
        "tc_10.txt",
        "tc_100.txt",
        "tc_1000.txt",
        "tc_5000.txt",
        "tc_10000.txt"
    };

    while(true){

        cout<<"\n";
        cout<<"========== ASSIGNMENT 2 ==========\n";
        cout<<"1. Traingle Counting\n";
        cout<<"2. Betweenness Centrality \n";
        cout<<"3. Connected Components\n";
        cout<<"0. Exit\n\n";

        int choice;
        cout<<"Enter Choice: ";
        cin>>choice;

        if(choice==0){
            break;
        }

        if(choice==1){

            compileIfNeeded("tc.exe","g++ ""driver/tc_driver.cpp ""src/triangle_count.cpp ""../Assignment_1/src/csr.cpp ""-o tc.exe");

            showTests(tcTests,".\\tc.exe");
        }

        else if(choice==2){

            compileIfNeeded("bc.exe","g++ ""driver/bc_driver.cpp ""src/bc.cpp ""../Assignment_1/src/csr.cpp ""../Assignment_1/src/bfs.cpp ""-o bc.exe");
            system("bc.exe");
        }

        else if(choice==3){

            compileIfNeeded("cc.exe","g++ ""driver/cc_driver.cpp ""src/cc.cpp ""../Assignment_1/src/csr.cpp ""../Assignment_1/src/bfs.cpp ""-o cc.exe");
            system("cc.exe");
        }

        else{
            cout<<"Invalid Choice\n";
        }
    }

    return 0;
}