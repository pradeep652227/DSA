   //https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
   class Node {
    public:
        int data;
        int row;
        int col;
        Node(int dataVal = -1, int rowVal = -1,int colVal = -1)
            : data{dataVal}, row{rowVal}, col{colVal} {}
    };
    class Compare {
    public:
        bool operator()(Node* a, Node* b) { return a->data > b->data; }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        if (k == 0)
            return {};
        priority_queue<Node*, vector<Node*>, Compare> minHeap;

        int maxElem = nums[0][0];
        // build a minHeap of size k
        for (int i = 0; i < nums.size(); i++) {
            int currElem = nums[i][0];
            if (currElem > maxElem)
                maxElem = currElem;
            Node* newNode = new Node(currElem,i,0);
            minHeap.push(newNode);
        }
        vector<int> smallest_range(2);
        smallest_range[0] = minHeap.top()->data;
        smallest_range[1] = maxElem;
        int minDiff=smallest_range[1]-smallest_range[0];

        while (!minHeap.empty()) {
            // get the minElem
            Node* minNode = minHeap.top();
            int diff = maxElem - minNode->data;
            if (diff < minDiff) {
                minDiff = diff;
                smallest_range[0] = minNode->data;
                smallest_range[1] = maxElem;
            } else if (minDiff==diff && smallest_range[0]>minNode->data) {
                //when two ranges are equal in diff, then check if a<c or not
                smallest_range[0]=minNode->data;
                smallest_range[1]=maxElem;
            }

            //remove the top elem
            minHeap.pop();
            //get the next elem;
            int minRow=minNode->row;
            int minCol=minNode->col;
            //only till the minSize of a vector
            if(minCol+1>=nums[minRow].size())
                break;
            minHeap.push(new Node(nums[minRow][minCol+1],minRow,minCol+1));
            //update maxElem with newRange
            if(nums[minRow][minCol+1]>maxElem)
                maxElem=nums[minRow][minCol+1];
        }

        return smallest_range;
    }