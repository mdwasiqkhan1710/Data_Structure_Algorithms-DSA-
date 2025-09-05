#include <iostream>
using namespace std;

int decToBinary(int decNum){
    int ans=0;
    int power=1;

    while(decNum>0){
        int rem = decNum%2;
        decNum = decNum/2;
        ans += (rem*power);
        power *= 10;
    }

    return ans;
}

int main(){
    //Printing binary form for 42 and 50
    cout<<"Binary form of 42: "<<decToBinary(42)<<endl;
    cout<<"Binary form of 50: "<<decToBinary(50)<<endl;

    return 0;
}