// Given an array arr[] of integers, where each element arr[i] represents the number of pages in the i-th book. 
// You also have an integer m representing the number of students. The task is to allocate books to each student such that:

// Each student receives atleast one book.
// Each student is assigned a contiguous sequence of books.
// No book is assigned to more than one student.
// The objective is to minimize the maximum number of pages assigned to any student. In other words, out of all possible allocations, find the arrangement where the student who receives the most pages still has the smallest possible maximum.

// Note: If it is not possible to allocate books to all students, return -1.

#include <iostream>
#include <vector> 
using namespace std;

bool isValid(vector<int>& arr, int n, int m, int maxAllowedPages){
    int stu=1; int pages=0;
    for(int i=0; i<n; i++){
        if(arr[i]>maxAllowedPages) return false;

        if(pages+arr[i]<=maxAllowedPages){
            pages += arr[i];
        }else{
            stu++;
            pages=arr[i];
        }
    }

    //checking if number of students we have gotten after completing the for loop is greater than given students.
    return stu > m ? false : true;
}

int allocateBooks(vector<int>& arr, int n, int m){

    //Edge case: If num of students is greater than number of books
    if(m>n) {
        return -1;
    }

    //Function for calculating total available pages for distribution
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }

    int ans=-1;
    int st=0, end=sum;

    while(st<=end){
        int mid=st+(end-st)/2;

        if(isValid(arr, n, m, mid)){
            ans=mid;
            end=mid-1;
        }else{
            st=mid+1;
        }
    }

    return ans;
}

int main(){
    vector<int> arr={2, 1, 3, 4};
    int m = 2;
    int n = arr.size();

    cout<<allocateBooks(arr, n, m);
    return 0;
}