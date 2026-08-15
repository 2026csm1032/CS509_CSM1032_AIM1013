#include<bits/stdc++.h>
using namespace std;

int main(){

    while(true){

        cout<<"\n========== PG SOFTWARE LAB ==========\n";
        cout<<"1. Assignment 1\n";
        cout<<"2. Assignment 2\n";
        cout<<"3. Assignment 3\n";
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
        if(choice==3){

            system(
                "cd ../assignment_3 && "
                "g++ ./driver/main_driver.cpp -o assignment_3"
            );

            system(
                "cd ../assignment_3 && "
                "assignment_3.exe"
            );
        }

        else{
            cout<<"Invalid Choice\n";
        }
    }

    return 0;
}