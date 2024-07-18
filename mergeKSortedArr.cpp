#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//mergeing k sorted array

class Info{
    public:
    int data;
    int rowIndex;
    int colIndex;

    Info(int data, int rowIndex, int colIndex){
        this->data = data;
        this->rowIndex = rowIndex;
        this->colIndex = colIndex;
    }
};

class compare{
    public:
    bool operator()(Info* a, Info* b){
        return a->data > b-> data;
    }
}; 

void mergekSortedArr(int arr[][4], int n, int k, vector<int> &ans){
    priority_queue<Info*, vector<Info*>, compare> pq;

    //step 1- process 1 element
    for(int row= 0;row <k ;row++){
        int element = arr[row][0];
        Info* temp = new Info(element,row,0);
        pq.push(temp);
    }

    while(! pq.empty()){
        Info* temp = pq.top();
        pq.pop();
        int topData = temp-> data;
        int topRow = temp ->rowIndex;
        int topCol = temp ->colIndex;

        ans.push_back(topData);
   
        if(topCol +1 < n){
            Info* newInfo = new Info(arr[topRow][topCol+1],topRow, topCol+1);
            pq.push(newInfo);
        }
    }
}

int main() {
    int arr[3][4] = {
        {1,4,8,11},
        {2,3,6,10},
        {5,7,12,14}
    };
    int n =4;
    int k =3;

    vector< int> ans;
    mergekSortedArr(arr,n,k,ans);

    cout<<"Printing the arr: "<<endl;
    for(int i =0;i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

}