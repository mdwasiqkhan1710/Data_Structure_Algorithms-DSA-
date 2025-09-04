//Write code to print the pattern below 
// *
// * *
// * * * 
// * * * *

#include <iostream>
using namespace std;

int main(){
    int n=4;

    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}


//Write code to print the pattern below 
// 1
// 2 2
// 3 3 3 3
// 4 4 4 4

int main(){
    int n=4; 
    int num=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cout<<num<<" ";
        }
        num++;
        cout<<endl;
    }
}