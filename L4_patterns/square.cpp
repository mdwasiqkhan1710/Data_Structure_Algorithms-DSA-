//Write the code to print the below pattern 
// 1 2 3 4
// 1 2 3 4
// 1 2 3 4
// 1 2 3 4

#include <iostream>
using namespace std;

int main(){
    int n=4;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

//Write the code to print the below pattern 
// 1 2 3 
// 4 5 6
// 7 8 9

int main(){
    int n=3;
    int num=1;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<num<<" ";
            num++;
        }
        cout<<endl;
    }
}

//Write the code to print the below pattern 
// A B C D 
// E F G H
// I J K L

int main(){
    char ch='A';
    int n=4;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<ch<< " ";
            ch++;
        }
        cout<<endl;
    }
}