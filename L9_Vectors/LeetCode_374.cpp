// Guess Number Higher or Lower

// Important part :
// You call a pre-defined API int guess(int num), which returns three possible results:

// -1: Your guess is higher than the number I picked (i.e. num > pick).
// 1: Your guess is lower than the number I picked (i.e. num < pick).
// 0: your guess is equal to the number I picked (i.e. num == pick).

#include <iostream>
#include <vector>
using namespace std;

int guessNumber(int n) {
        int st=1;
        int end=n;

        while(st<=end){
            int mid=st+(end-st)/2;

            // Here guess(int n) is actually a fuction given is question itself
            int res = guess(mid);
            
            if(res==0) return mid;

            if(res == -1){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return -1;
    }

int main(){
    int n = 10;
    int pick = 6;

    cout<<guessNumber(n)<<endl;
    return 0;
}