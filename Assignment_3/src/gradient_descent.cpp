#include "gradient_descent.h"

double evaluatePolynomial(vector<double>& coeffs,double x){

    double value=0;

    for(int i=0;i<coeffs.size();i++){
        value+=coeffs[i]*pow(x,i);
    }

    return value;
}

double evaluateDerivative(vector<double>& coeffs,double x){

    double value=0;

    for(int i=1;i<coeffs.size();i++){
        value+=i*coeffs[i]*pow(x,i-1);
    }

    return value;
}

GradientDescentResult gradientDescent(
    vector<double>& coeffs,
    double initialX,
    double learningRate,
    double tolerance,
    int maxIterations
){

    double x=initialX;

    int iteration=0;

    bool converged=false;

    while(iteration<maxIterations){

        double gradient=evaluateDerivative(coeffs,x);

        if(abs(gradient)<=tolerance){

            converged=true;
            break;
        }

        x=x-learningRate*gradient;

        iteration++;
    }

    GradientDescentResult result;

    result.finalX=x;
    result.finalValue=evaluatePolynomial(coeffs,x);
    result.iterations=iteration;
    result.converged=converged;

    return result;
}