#include<bits/stdc++.h>
using namespace std;

int main(){

    while(true){

        cout<<"\n========== PG SOFTWARE LAB ==========\n";
        cout<<"1. Assignment 1\n";
        cout<<"0. Exit\n\n";

        int choice;
        cout<<"Enter Choice: ";
        cin>>choice;

        if(choice==0){
            break;
        }

        if(choice==1){

            system(
                "cd ../assignment_1 && "
                "g++ ./driver/main_driver.cpp -o assignment_1"
            );

            system(
                "cd ../assignment_1 && "
                "assignment_1.exe"
            );
        }
        if(choice==2){

            system(
                "cd ../assignment_2 && "
                "g++ ./driver/main_driver.cpp -o assignment_2"
            );

            system(
                "cd ../assignment_2 && "
                "assignment_2.exe"
            );
        }

        else{
            cout<<"Invalid Choice\n";
        }
    }

    return 0;
}