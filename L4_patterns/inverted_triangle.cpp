//Write the code to print the pattern below
//1 1 1 1
//  2 2 2
//    3 3
//      4

#include <iostream>
using namespace std;

int main(){
    int n=4;

    for(int i=0; i<n; i++){
        //Printing spaces
        for(int j=0; j<i; j++){
            cout<<" ";
        }
        //Printing numbers
        for(int k=0; k<n-i; k++){
            cout<<i+1;
        }
        cout<<endl;
    }
}