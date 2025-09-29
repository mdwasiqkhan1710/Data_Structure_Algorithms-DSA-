//Reverse String

// Write a function that reverses a string. The input string is given as an array of characters s.

#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char>& s) {
        
        int st = 0, end = s.size()-1;

        while(st<=end){
            swap(s[st], s[end]);
            st++;
            end--;
        }
}

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};  
    
    cout << "Original: ";
    for(char c : s) {
        cout << c << " ";
    }
    cout << endl;
    
    reverseString(s); 
    
    cout << "Reversed: ";
    for(char c : s) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}