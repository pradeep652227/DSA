int IsAllocationPossible(vector<int>& arr, int mid, int m) {
    int sumOfPages(0);
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > mid)
            return 0;

        if (sumOfPages + arr[i] > mid) {
            m--;  // Assign next sum to the next student
            if (m == 0)
                return 0;  // No more students left
            sumOfPages = arr[i];  // Start sum for next student
        } else {
            sumOfPages += arr[i];
        }
    }
    //when all the students are assigned the books.
    //That is, a valid Allocation
    return 1;
}

int findPages(vector<int>& arr, int n, int m) {
    if (m > n || m == 0)
        return -1;

    int maxPages(arr[0]);
    int totalPages(0);
    for (auto &elem : arr) {
        maxPages = max(maxPages, elem);
        totalPages += elem;
    }
    if (m == 1)
        return totalPages;
    if (m == n)
        return maxPages;

    int l = maxPages;  // Lowest pages a student can get
    int r = totalPages;  // Highest pages a student can get
    int ans = arr[0];

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (IsAllocationPossible(arr, mid, m)) {
            ans = mid;
            r = mid - 1;  // Try to get a minimum value
        } else {
            l = mid + 1;  // The answer will lie in the right half
        }
    }

    return ans;
}
