//Write code to print the pattern below 
// 1
// 2 1
// 3 2 1
// 4 3 2 1

#include <iostream>
using namespace std;

int main(){
    int n = 4;

    for(int i=0; i<n; i++){
        for(int j=i+1; j>0; j--){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

//Write code to print the pattern below --- Floydds Triangle 
// 1
// 2 3
// 4 5 6
// 7 8 9 10

int main(){
    int n=4;
    int num=1;
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cout<<num<<" ";
            num++;
        }
        cout<<endl;
    }
}

//Write code to print the pattern below 
// A
// B C
// D E F
// G H I J

int main(){
    int n=4;
    char ch='A';
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cout<<ch<<" ";
            ch++;
        }
        cout<<endl;
    }
}