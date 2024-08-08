//https://leetcode.com/problems/find-median-from-data-stream/description/
// Simple Question Form - https://www.naukri.com/code360/problems/median-in-a-stream_975268?leftPanelTabValue=PROBLEM

   // Max-Heap for the lower half
    std::priority_queue<int> maxHeap;
    // Min-Heap for the upper half
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    // Function to balance the heaps
    void balanceHeaps() {
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    void addNum(int num) {

        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        balanceHeaps();

    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        } else {
            return minHeap.top();
        }
    }