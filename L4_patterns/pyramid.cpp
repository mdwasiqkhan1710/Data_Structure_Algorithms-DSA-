//Write the code to print the below pattern -
//       1
//     1 2 1
//   1 2 3 2 1
// 1 2 3 4 3 2 1

#include <iostream>
using namespace std;

int main(){
    int n=8;

    for(int i=0; i<n; i++){

        //Right Half Pyramid
        for(int j=0; j<n-i-1; j++){ //Spaces
            cout<<" ";
        }
        for(int k=0; k<i+1; k++){//digits
            cout<<k+1;
        }

        //Left Hald Pyramid
        for(int j=i; j>0; j--){
            if(i==0) cout<<endl;
            else {
                cout<<j;
            }
        }

        cout<<endl;
    }
}