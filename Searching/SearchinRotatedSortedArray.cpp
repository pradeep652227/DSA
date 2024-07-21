    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1){
            if(nums[0]==target)
            return 0;
            else
                return -1;
        }
            
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target)
                return mid;
            //if left half is sorted
            if(nums[l]<=nums[mid]){
            //check if target is pres in this half
                if(nums[l]<=target && target<=nums[mid])
                        r=mid;
                else
                    l=mid+1;
            }
            else{
                //right half is sorted
                if(target>nums[mid]&& target<=nums[r])
                    l=mid+1;
                else
                    r=mid;
            }
        }

        return -1;
    }