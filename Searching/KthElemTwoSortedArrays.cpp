 int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n>m)
            return kthElement(arr2,arr1,m,n,k);
        //considering, arr1 to be the smaller array  
       
        int l=max(0,k-m);//min of 0 or k-m elems from arr1
        int r=min(k,n);//max (k,n) elems from arr1
        while(l<=r){
            int mid1=l+(r-l)/2;
            int mid2=k-mid1;
            int l1=(mid1==0)?INT_MIN:arr1[mid1-1];
            int l2=(mid2==0)?INT_MIN:arr2[mid2-1];
            int r1=(mid1==n)?INT_MAX:arr1[mid1];
            int r2=(mid2==m)?INT_MAX:arr2[mid2];
            
            if(l1<=r2 && l2<=r1){
                return max(l1,l2);
            }
            else if(l1>r2)
                r=mid1-1;//get smaller elems on the left
            else 
                l=mid1+1;
        }
        
        return -1;
        // int i=0,j=0;
        // int cnt(0);
        // if(k>n+m)
        //     return -1;
            
        // while(i<n && j<m && cnt<=k){
        //     if(arr1[i]<=arr2[j]){
        //         cnt++;
        //         if(cnt==k)
        //             return arr1[i];
        //             i++;
        //     }else{
        //         cnt++;
        //         if(cnt==k)
        //             return arr2[j];  
        //             j++;
        //     }
        // }
        // while(i<n && cnt<=k){
        //   cnt++;
        //     if(cnt==k)
        //         return arr1[i]; 
        // i++;
        // }
        // while(j<m && cnt<=k){
        //     cnt++;
        //     if(cnt==k)
        //         return arr2[j];
        //     j++;
        // }
        
        // return -1;
    }