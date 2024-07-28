  //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
            while(i<n){
                int maxIdx=i;
                int leftIdx=2*i+1;
                int rightIdx=2*i+2;
                if(leftIdx<n && arr[leftIdx]>arr[maxIdx])
                    maxIdx=leftIdx;
                if(rightIdx<n && arr[rightIdx]>arr[maxIdx])
                    maxIdx=rightIdx;
                if(maxIdx==i)//this subtree is already heapified
                    break;
                swap(arr[maxIdx],arr[i]);
                i=maxIdx;//jump to the affected subtree's root
            }
            return;
    }
  //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        //n/2+1 to n elems are the root nodes and they are already heapified
        //so 
        int startIdx=n/2-1;
        for(int i=startIdx;i>=0;i--){
            heapify(arr,n,i);
        }
    }
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
       //1st buildHeap - maxHeap
     buildHeap(arr,n);

       //now from i=0 to i=n-1 
       /*
       1.)Heapify from i=start to len
       2.)swap(arr[0],arr[len]);
       len=len-1;
       */
       
       int len(n);
       for(int i=0;i<n-1;i++){
        swap(arr[0],arr[len-1]);
        len--; 
        heapify(arr,len,0);
       }
       
       return;
    }
