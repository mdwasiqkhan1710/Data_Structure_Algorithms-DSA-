#include <iostream>
using namespace std;

int binaryToDec(int binaryNum){
    int ans=0;
    int power=1;

    while(binaryNum>0){
        int rem = binaryNum%2;
        binaryNum = binaryNum/10;

        ans += (rem*power);
        power *= 2;
    }

    return ans;
}

int main(){
    
    //converting binary form : 101010 and 110010 into decimal form
    cout<<"Decimal form of 42: "<<binaryToDec(101010)<<endl;
    cout<<"Decimal form of 42: "<<binaryToDec(110010)<<endl;

    return 0;
}