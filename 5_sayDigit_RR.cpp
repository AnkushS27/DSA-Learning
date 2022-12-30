#include <iostream>
#include <string>

using namespace std;

void count(int n, string arr[]){
    //base case
    if(n==0){
        return;
    }
    
    //Processing
    int digit = n%10;
    n = n/10;
    
    //RR
    count(n,arr);
    
    cout<<arr[digit]<<" ";
    
}

int main()
{
    int num = 112424;
    
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    count(num, arr);
    
    return 0;
}