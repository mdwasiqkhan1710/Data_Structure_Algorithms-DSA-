// Binary Exponentiation --- Power(x,n)
// Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).

#include <iostream>
using namespace std;

double power(double x, double n){
    long binForm = n;

    if(n<0){
        x = 1/x;
        binForm = -binForm;
    }

    double ans = 1;

    while(binForm>0){
        if(binForm%2 == 1){
            ans *= x;
        }
        x *= x;
        binForm = binForm/2;
    }
    return ans;
}

int main(){
    double x = 5;
    double n = -1;

    double ans = power(x, n);
    cout<<"Given x:"<<x<<" raised to power of n:"<<n<<" equals to -: "<<ans<<endl;

    return 0;
}