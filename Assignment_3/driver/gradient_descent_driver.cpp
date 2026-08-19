#include<bits/stdc++.h>
#include "../src/gradient_descent.h"
using namespace std;

int main(int argc,char* argv[]){

    if(argc!=2){

        cout<<"Usage: gradient_descent input_file\n";
        return 0;
    }

    string filePath="./test/";
    filePath+=argv[1];

    ifstream fin(filePath);

    if(!fin){

        cout<<"Input file not found\n";
        return 0;
    }

    string temp;

    int degree;
    fin>>temp>>degree;

    vector<double> coeffs(degree+1);

    fin>>temp;

    for(int i=0;i<=degree;i++){
        fin>>coeffs[i];
    }

    double initialX;
    fin>>temp>>initialX;

    double learningRate;
    fin>>temp>>learningRate;

    double tolerance;
    fin>>temp>>tolerance;

    int maxIterations;
    fin>>temp>>maxIterations;

    auto start=chrono::high_resolution_clock::now();

    GradientDescentResult result=gradientDescent(
        coeffs,
        initialX,
        learningRate,
        tolerance,
        maxIterations
    );

    auto end=chrono::high_resolution_clock::now();

    double executionTime=
    chrono::duration<double,milli>(end-start).count();

    string outputFile="./output/gd_output_"+string(argv[1]);

    ofstream fout(outputFile);

    fout<<fixed<<setprecision(12);

    fout<<"Algorithm: Gradient Descent\n";
    fout<<"Degree: "<<degree<<"\n";
    fout<<"Final x: "<<result.finalX<<"\n";
    fout<<"Final f(x): "<<result.finalValue<<"\n";
    fout<<"Iterations: "<<result.iterations<<"\n";
    fout<<"Converged: "
        <<(result.converged?"true":"false")
        <<"\n";

    fout<<"Execution Time: "
        <<executionTime
        <<" ms\n";

    fout.close();

    cout<<"Output written to: "<<outputFile<<"\n";

    return 0;
}