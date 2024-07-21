    double checkEdgeCase(vector<int>& nums) {
        int m=nums.size();
            if (m & 1)
                return nums[m / 2];
            return (double)(nums[m / 2] + nums[m / 2 - 1]) / 2.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();
        if(n==0)
            return checkEdgeCase(nums2);
        if(m==0)
            return checkEdgeCase(nums1);
        
        if (n > m)
            return findMedianSortedArrays(nums2, nums1);
        // assuming nums1 is smaller

        int &n1 = n, &n2 = m;
        int total = n + m;
        int left = (n + m + 1) >> 1; // elems in left half
        int l = 0, r = n;
        while (l <= r) {
            int mid1 = l + (r - l) / 2;
            int mid2 = left - mid1;
            int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int r1 = (mid1 == n) ? INT_MAX : nums1[mid1];
            int r2 = (mid2 == m) ? INT_MAX : nums2[mid2];

            if (l1 <= r2 && l2 <= r1) {
                if (total & 1) // when there are odd total elems
                    return (double)max(l1, l2);
                return static_cast<double>((max(l1, l2) + min(r1, r2)) / 2.0);
            } else if (l1 > r2) // get smaller value in left half;
                r = mid1 - 1;
            else
                l = mid1 + 1;
        }
        return 0.0;
    }