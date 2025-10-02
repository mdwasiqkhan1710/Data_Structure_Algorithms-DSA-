//Valid Palindrome

//A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.

#include<iostream>
#include<string>
using namespace std;

bool isAlphaNum(char ch){
    if((ch>='0' && ch<='9') || (ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
        return true;
    }

    return false;
}

bool isPalindrome(string s){
    int n=s.length();
    int st=0, end=n-1;

    while(st<end){
        while(st<end && !isAlphaNum(s[st])){
            st++;
        }
        while(st<end && !isAlphaNum(s[st])){
            end--;
        }

        if(tolower(s[st] != tolower(s[end]))){
            return false;
        }else{
            st++;
            end--;
        }
    }

    return true;
}

int main(){
    string s = "race a car";

    bool ans = isPalindrome(s);

    cout<<"If your given string is Palindrome ans will be 1 or else 0"<<endl;
    cout<<"Answer: "<<ans<<endl;

    return 0;
}
