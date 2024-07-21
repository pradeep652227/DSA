    int singleNonDuplicate(vector<int>& nums) {
        // int xor_val=0;
        // for(int &elem:nums)
        //     xor_val^=elem;

        // return xor_val;

        int n = nums.size();
        if (n == 1)
            return nums.at(0);
        int l=0,r=n-2;
        while(l<=r){
            int mid=l+(r-l)/2;

            if(nums[mid]==nums[mid^1])
                l=mid+1;
            else
                r=mid-1;
        }

        return nums[l];
        // int l = 0, r = n - 1;
        // while (l <= r) {
        //     if (l+1<n) {
        //         if (nums[l] == nums[l + 1])
        //             l += 2;
        //         else 
        //             return nums[l];
        //     }
        //     if(r-1>=0){
        //         if(nums[r]==nums[r-1])
        //             r-=2;
        //         else
        //             return nums[r];
        //     }
        //     if(l>r)
        //         break;
        // }

        // return -1;
    }