#include <iostream>
#include <queue>

using namespace std;

class heap{
    public:
    
    int arr[100];
    int size;
    
    heap(){
        arr[0] = -1;
        size = 0;
    }
    
    void insert(int val){
        size = size + 1;
        
        int index = size;
        arr[index] = val;
        
        while(index > 1){
            int parent = index/2;
            
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            } else{
                return ;
            }
        }
        
        // T.C = O(logn)
    }
    
    void deletion(){
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return ;
        }
        
        // step1: put last element into first index
        arr[1] = arr[size];
        
        // step2: remove last element
        size--;
        
        // step3: take root node to its correct position
        int i=1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;
            
            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            } else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            } else{
                return ;
            }
        }
        
        // T.C = O(logn)
    }
    
    void print(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;
    
    if(left<=n && arr[largest] < arr[left]){
        largest = left;
    } 
    if(right<=n && arr[largest] < arr[right]){
        largest = right;
    }
    
    if(largest!=i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
    
    // T.C = O(logn)
}

void heapSort(int arr[], int n){
    int size = n;
    
    while(size>1){
        // step1: swaping last and first element
        swap(arr[1], arr[size]);
        size--;
        
        // step2: making heap by taking element to correct position
        heapify(arr, size, 1);
    }
    
    // T.C = O(nlogn)
}

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    
    h.deletion();
    h.print();
    
    // for heapify
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n=5;
    
    for(int i=n/2; i>0; i--){
        heapify(arr, n, i);
        // T.C = O(n)
    }
    
    cout<<"\nBuilded heap from the array"<<endl;
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
    
    // for heapSort
    
    heapSort(arr, n);
    
    cout<<"After heap Sort"<<endl;
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }
    
    // Through Priority Queue you can use max heap and min heap from STL
    
    cout<<"\n\nUsing Priority queue"<<endl;
    
    priority_queue<int> pq;   //maxheap
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(3);
    
    cout<<"At top : "<<pq.top()<<endl;
    pq.pop();
    cout<<"At top : "<<pq.top()<<endl;
    cout<<"Size : "<<pq.size()<<endl;
    
    priority_queue<int, vector<int>, greater<int>> pq2;   //minheap
    
    pq2.push(4);
    pq2.push(2);
    pq2.push(5);
    pq2.push(3);
    
    cout<<"\nAt top : "<<pq2.top()<<endl;
    pq2.pop();
    cout<<"At top : "<<pq2.top()<<endl;
    cout<<"Size : "<<pq2.size()<<endl;
    
    return 0;
}
