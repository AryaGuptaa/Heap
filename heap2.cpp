#include<iostream>
#include<queue>
#include<limits.h>
using namespace std;

// priority queue
//get Kth smallest element
//get Kth greatest element
//vaild CBT


int kthSmallestElement(int arr[], int n, int k){
    priority_queue<int>pq;

    for(int i =0; i< k; i++){
        int element = arr[i];
        pq.push(element);
    }
    for(int i = k; i<n; i++){
        int element = arr[i];
        if(element < pq.top()){
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;
}

int kthGreatestElement(int arr[], int n, int k){
    priority_queue<int, vector<int>, greater<int>>pq;

    for(int i = 0; i<k; i++){
        int element = arr[i];
        pq.push(element);
    }
    for(int i =k; i<n;i++){
        int element = arr[i];
        if(element > pq.top()){
            pq.pop();
            pq.push(element);
        }
    }
    int ans= pq.top();
    return ans;
}

// check max heap || check valid CBT

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this -> data = data;
        this-> left = NULL;
        this-> right = NULL;
    }
};

class Info{
    public:
    int maxVal;
    bool isHeap;

    Info(int data, bool isHeap){
        this-> maxVal = data;
        this-> isHeap = isHeap;
    }
};

Info checkMaxHeap(Node* root){

    //base case
    if(root == NULL){
        Info ans(INT_MIN, true);
        return ans;
    }

    if(root-> left == NULL && root-> right == NULL){
        Info ans(root-> data, true);
        return ans;
    }

    Info leftAns = checkMaxHeap(root-> left);
    Info rightAns = checkMaxHeap(root -> right);

    if(root->data > leftAns.maxVal && root-> data > rightAns.maxVal && leftAns.isHeap && rightAns.isHeap){
        Info ans(root->data,true);
        return ans;
    }
    else{
        Info ans(max(root-> data, max(leftAns.maxVal, rightAns.maxVal)),false);
        return ans;
    }
   
}

int main() {


    // priority_queue<int>pq;
    // pq.push(10);
    // pq.push(20);
    // pq.push(30);
    // pq.push(40);
    // pq.push(50);

    // cout<<"Top element: "<<pq.top()<<endl;
    // pq.pop();
    // cout<<"Top element: "<<pq.top()<<endl;
    // cout<<"SIze of max heap: "<<pq.size()<<endl;

    // if(pq.empty()){
    //     cout<<"empty!"<<endl;
    // }
    // else{
    //     cout<<"not empty"<<endl;
    // }

    //creation of min heap
    // priority_queue<int, vector<int>, greater<int>>pq;

    // //insertion
    // pq.push(30);
    // pq.push(40);
    // pq.push(50);
    // pq.push(10);
    // pq.push(20);
    // cout<<"Top element: "<<pq.top()<<endl;         //smallest element


    int arr[] ={3,4,5,7,8,9,6};
    int n =7;
    int k = 4;
    cout<<k<<"th smallest element is: "<<kthSmallestElement(arr,n,k)<<endl;
    cout<<k<<"th largest element is: "<<kthGreatestElement(arr,n,k)<<endl;


}