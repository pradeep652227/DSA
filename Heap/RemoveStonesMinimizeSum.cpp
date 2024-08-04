//  https://leetcode.com/problems/remove-stones-to-minimize-the-total/
   void heapifyMaxHeap(vector<int>& piles,int n,int idx){
            while(idx<n/2){
                 int leftIdx=2*idx+1;
                 int rightIdx=2*idx+2;
                 int maxIdx=idx;
                 if(leftIdx<n && piles[leftIdx]>piles[maxIdx])
                    maxIdx=leftIdx;
                 if(rightIdx<n && piles[rightIdx]>piles[maxIdx])
                    maxIdx=rightIdx;
                 if(maxIdx==idx)
                     break;
                 swap(piles[maxIdx],piles[idx]);
                 idx=maxIdx;
            }
            return;
    }
    void buildHeap(vector<int>& piles){
        int n=piles.size();
        int startIdx=n/2-1;
        for(int i=startIdx;i>=0;i--){
                heapifyMaxHeap(piles,n,i);
        }
    }
    void removeTopElem(vector<int>& piles,int n){
        //first add leaf elem to top
        piles[0]=piles[n-1];
        //heapify from i=0 to i=n-1
        heapifyMaxHeap(piles,n-1,0);
        return;
    }
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        // build a maxHeap to perform piles[i]-piles[i]/2 operations k times
         buildHeap(piles);
        while(k--){
            int maxElem=piles[0];
            maxElem=maxElem-floor(maxElem/2);
            piles[0]=maxElem;
            heapifyMaxHeap(piles,n,0);
        }

        int sum(0);
        while(n!=0){
            sum=sum+piles[0];
            removeTopElem(piles,n);
            n--;
        }

        return sum;
    }