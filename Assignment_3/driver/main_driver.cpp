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

    vector<string> gdTests={
        "gd_01.txt",
        "gd_02.txt",
        "gd_03.txt",
        "gd_04.txt",
        "gd_05.txt"
    };


    while(true){

        cout<<"\n";
        cout<<"========== ASSIGNMENT 3 ==========\n";
        cout<<"1. Gradient Descent\n";
        cout<<"2. Maxflow-Mincut\n";
        cout<<"0. Exit\n\n";

        int choice;
        cout<<"Enter Choice: ";
        cin>>choice;

        if(choice==0){
            break;
        }

        if(choice==1){

            compileIfNeeded(
                "gradient_descent.exe",
                "g++ driver/gradient_descent_driver.cpp src/gradient_descent.cpp -o gradient_descent.exe"
            );

            showTests(gdTests,".\\gradient_descent.exe");
        }

        else if(choice==2){

            compileIfNeeded(
                "maxflow_mincut.exe",
                "g++ driver/maxf_driver.cpp ../Assignment_1/src/csr.cpp src/maxf.cpp -o maxflow_mincut.exe"
            );

            system("maxflow_mincut.exe");
        }

        else{

            cout<<"Invalid Choice\n";
        }
    }

    return 0;
}