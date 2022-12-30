#include <bits/stdc++.h>

using namespace std;

void bubblesort(int *arr, int n){
    // Base Case
    if(n<0){
        return;
    }
    
    if(arr[0]>arr[1]){
        swap(arr[0],arr[1]);
    }
    
    return bubblesort(arr+1, n-1);
}

void numbers(int arr[], int n, int i){
    if(i==n+1){
        return;
    }
    
    bubblesort(arr, n);
    
    return numbers(arr, n, i+1);
}

void print(int *arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
}

int main()
{
    int arr[] = {1, 7, -2, 9, 8, 10, 3, 45, 4};
    
    print(arr,9);
    
    numbers(arr,9,0);
    
    print(arr,9);
    
    return 0;
}