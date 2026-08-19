#ifndef GRADIENT_DESCENT_H
#define GRADIENT_DESCENT_H

#include<bits/stdc++.h>
using namespace std;

struct GradientDescentResult{

    double finalX;
    double finalValue;
    int iterations;
    bool converged;
};

GradientDescentResult gradientDescent(
    vector<double>& coeffs,
    double initialX,
    double learningRate,
    double tolerance,
    int maxIterations
);

#endif