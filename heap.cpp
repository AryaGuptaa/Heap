#include<iostream>
using namespace std;

class Heap{
    public:
    int *arr;
    int size;
    int capacity;

    Heap(int capacity){
        this->arr = new int[capacity];
        this-> capacity = capacity;
        this->size = 0;
    }

    void insert(int val) {
        if(size == capacity){
            cout<<"Heap overflow"<<endl;
            return;
        }

        size++;
        int index = size;
        arr[index] =val;

        while(index > 1){
            int parentIndex = index/2;
            if(arr[index] > arr[parentIndex]) {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else{
                break;
            }
        }
    }

    void print(){
        cout<<"Printing the content of heap: "<< endl;
    for(int i = 1; i<=size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    }

    int deleteHeap(){
        int answer = arr[1];
        arr[1] = arr[size];

        size--;
        int index =1;
        while(index< size) {
            int leftIndex = 2*index;
            int rightIndex = 2*index +1;

            int largestWalaIdx = index;
            if(leftIndex <= size && arr[largestWalaIdx] < arr[leftIndex]){
                largestWalaIdx = leftIndex;
            }
            if(rightIndex <= size && arr[largestWalaIdx] < arr[rightIndex]){
                largestWalaIdx = rightIndex;
            }

            if(index == largestWalaIdx){
                break;
            }
            else{
                swap(arr[index], arr[largestWalaIdx]);
                index = largestWalaIdx;
            }
        }
        return answer;
    }

};

 void heapify(int *arr, int n, int index){       // o(n)
        int leftIndex = 2*index;
        int rightIndex = 2*index+1;
        int largestWalaIdx= index;

        if(leftIndex <= n && arr[largestWalaIdx] < arr[leftIndex]){
                largestWalaIdx = leftIndex;
        }
        if(rightIndex <= n && arr[largestWalaIdx] < arr[rightIndex]){
            largestWalaIdx = rightIndex;
        }

        if(index != largestWalaIdx){
            swap(arr[index], arr[largestWalaIdx]);
            index = largestWalaIdx;
            heapify(arr,n,index);
        }
    }

    void buildHeap(int arr[], int n){
        for(int index = n/2; index > 0;index--){
            heapify(arr,n,index);
        }
    }

    void heapSort(int arr[], int n) {
        while(n != 1){
            swap(arr[1], arr[n]);
            n--;
            heapify(arr,n,1);
        }
    }

int main(){

    int arr[] ={-1,5,10,15,20,25,12};
    // int n = 6;
    buildHeap(arr,6);
    cout<<"printing heap: "<<endl;
    for(int i = 1; i<=6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapSort(arr,6);
    cout<<"printing heap: "<<endl;
    for(int i = 1; i<=6;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
    
    // Heap h(20);
    // h.insert(10);
    // h.insert(20);
    // h.insert(5);
    // h.insert(11);
    // h.insert(6);

    // h.print();
    // int ans = h.deleteHeap();
    // cout<<"deleted ans: "<<ans<<endl;
    // h.print();
    
};