    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i=0,j=0;
        int cnt(0);
        if(k>n+m)
            return -1;
            
        while(i<n && j<m && cnt<=k){
            if(arr1[i]<=arr2[j]){
                cnt++;
                if(cnt==k)
                    return arr1[i];
                    i++;
            }else{
                cnt++;
                if(cnt==k)
                    return arr2[j];  
                    j++;
            }
        }
        while(i<n && cnt<=k){
          cnt++;
            if(cnt==k)
                return arr1[i]; 
        i++;
        }
        while(j<m && cnt<=k){
            cnt++;
            if(cnt==k)
                return arr2[j];
            j++;
        }
        
        return -1;
    }