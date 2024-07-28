
#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i) {
    
    while(i<n){
        int minIdx=i;
        int leftIdx=2*i+1;
        int rightIdx=2*i+2;
        if(leftIdx<n && arr[leftIdx]<arr[minIdx])
            minIdx=leftIdx;
        if(rightIdx<n && arr[rightIdx]<arr[minIdx])
            minIdx=rightIdx;
        if(minIdx==i)
            break;
        swap(arr[minIdx],arr[i]);
        i=minIdx;
    }
}

void buildMinHeap(int arr[], int n) {
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;

    // Perform reverse level order traversal from last non-leaf node and heapify each node
    for (int i = startIdx; i >= 0; i--) {
        //heapify each subtree
        heapify(arr, n, i);
    }
}

    void popElem(int arr[],int n){
        //remove the top element
        arr[0]=arr[n-1];
        //now heapify the array from i=0 to i=n-2
        heapify(arr,n-1,0);
        return;
    }

int kthSmallest(int arr[], int l, int r, int k) {
    int n = r - l + 1;

    // First convert array into minHeap
    buildMinHeap(arr, n);

      for(int i=0;i<k-1;i++){
        popElem(arr,n);
        n--;
    }
    return arr[0];
}


int main()
{

        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        cout<<kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    return 0;
}
