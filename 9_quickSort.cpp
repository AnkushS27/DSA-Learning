#include <iostream>
using namespace std;

int partition(int *arr, int s, int e){
    int pivot = arr[s];
    int count = 0;

    for(int i=s+1; i<=e; i++){
        if(arr[i]<=pivot){
            count++;
        }
    }

    int p = count+s;
    swap(arr[p],arr[s]);

    int i=s, j=e;
    while(i<p && j>p){
        while(arr[i] <= pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i<p && j>p){
            swap(arr[i++], arr[j--]);
        }
    }

    return p;
}

void quickSort(int *arr, int s, int e){
    //base case
    if(s>=e){
        return;
    }
    
    // partition finding
    int p = partition(arr, s, e);
    // cout<<p;

    // sorting left part
    quickSort(arr, s, p-1);

    // sorting right part
    quickSort(arr, p+1, e);
}

int main()
{
    int n=10;
    int arr[n] = {1, 6, 3, 5, 7, 9, 12, 10, 2, 4};
    
    quickSort(arr, 0, n-1);
    
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}