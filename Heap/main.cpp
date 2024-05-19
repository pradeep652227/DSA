#include <iostream>

using namespace std;

class Heap{
public:    
    int size;
    int *arr;
    int idx;
    Heap(int n=0):size{n},arr{nullptr},idx{0}{
        arr=new int[n+1];
        //for 1-based indexing
        arr[0]=-1;
    }
    void insert(int value);
    void deleteNode();

    ~Heap(){
        size=0;
        idx=0;
        arr=nullptr;
        cout<<"Heap Deleted"<<endl;
        delete [] arr;
    }
};

void print_maxHeap(Heap& maxHeap, int n);
void heapify(int arr[],int n,int idx);

int main(){
    Heap maxHeap(100);
    // int* arr=maxHeap.arr;
    // arr[1]=100; arr[2]=50; arr[3]=60, arr[4]=30,arr[5]=40,arr[6]=45,arr[7]=55, arr[8]=10, arr[9]=20;
    // maxHeap.idx=9;
    // maxHeap.insert(100);
    // maxHeap.insert(50);
    // maxHeap.insert(60);
    // maxHeap.insert(30);
    // maxHeap.insert(40);
    // maxHeap.insert(45);
    // maxHeap.insert(55);
    // maxHeap.insert(10);
    // maxHeap.insert(20);
    // print_maxHeap(maxHeap,maxHeap.idx);
    // maxHeap.insert(57);

    // cout<<"After inserting "; print_maxHeap(maxHeap,maxHeap.idx);
    // maxHeap.deleteNode();
    // cout<<"After deleting "; print_maxHeap(maxHeap,maxHeap.idx);

    int arr1[]={-1,1,2,3,4,5};
    heapify(arr1,5,1);
    heapify(arr1,5,1);
    cout<<"After heapifying, the array becomes- ";for(auto& elem:arr1) cout<<elem<<" "; cout<<endl;
    return 0;
}

void print_maxHeap(Heap& maxHeap,int n){
    int* arr=maxHeap.arr;
    for(int i=1;i<=n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;

    return;
}

void Heap::insert(int value){
//for 1-based index
    idx=idx+1;   
     if(idx>size+1){
        cout<<"Cannot add more"<<endl;
        return;
    }
    if(idx==1){
        arr[1]=value;
        return;
    }

    int childIdx=idx;
    arr[childIdx]=value;
    int parentIdx=childIdx/2;
    
        while(arr[parentIdx]<value && parentIdx>=1){
            swap(arr[parentIdx],arr[childIdx]);
            childIdx=parentIdx;
            parentIdx=parentIdx/2;
        }

        return;
}

void Heap::deleteNode(){
    int lastNodeValue=arr[idx];
    idx--;
    //replace root node's value with the last node's 
    arr[1]=lastNodeValue;

    //Update the root node with the correct position of the current root node
    int parIdx=1; 
    while(parIdx<idx){
        int largest=parIdx;
        if(2*parIdx <=idx){
            int leftChild_idx=2*parIdx;
            if(arr[leftChild_idx]>arr[largest])
                largest=leftChild_idx;
        }
        if(2*parIdx+1 <=idx){
            int rightChild_idx=2*parIdx+1;
            if(arr[rightChild_idx]>arr[largest])
                largest=rightChild_idx;
        }
        if(parIdx==largest)
            return;
        swap(arr[parIdx],arr[largest]);
        parIdx=largest;
    }
    
    return;
}

void heapify(int arr[],int n,int idx){
    //considering 1-based array
    if(idx>=n)
        return;
    int left=2*idx;
    int right=2*idx+1;
    int largest=idx;

    if(left<=n && arr[left]>arr[largest])
        largest=left;
    if(right<=n && arr[right]>arr[largest])
        largest=right;
    
    if(largest==idx)//base case
        return;

    swap(arr[idx],arr[largest]);
    heapify(arr,n,largest);//calling the same function again
}