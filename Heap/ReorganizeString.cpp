//https://leetcode.com/problems/reorganize-string/

    class Node{
        public:
        char data;
        int count;
        Node(char dataVal='\n',int countVal=-1)
            :data{dataVal},count{countVal}
            {}
    };
    class Compare{
        public:
        bool operator()(Node* a,Node* b){
            return a->count < b->count;
        }
    };
    string reorganizeString(string s) {
        int n = s.length();
        if (n <= 1)
            return s;
        if (n == 2) {
            if (s[0] == s[1])
                return "";
            return s;
        }

        int frequencies[26]{0};
        for(auto &ch:s)
            frequencies[ch-'a']++;
        //now create a maxHeap
        priority_queue<Node*,vector<Node*>,Compare>maxHeap;

        for(int i=0;i<26;i++){
            if(frequencies[i]!=0)
                maxHeap.push(new Node(i+'a',frequencies[i]));
        }
        //now maxHeap is created based on the nodes having higher frequency are on the top

        string ans{""};
        while(maxHeap.size()>1){
                //get top two elements of the maxHeap
            Node* topElem1=maxHeap.top();
            maxHeap.pop();
            Node* topElem2=maxHeap.top();
            maxHeap.pop();

            //add them to the ans string
            ans+=topElem1->data;
            ans+=topElem2->data;
            //reduce their counts
            topElem1->count--;
            topElem2->count--;

            //insert them back to the heap if counts are not zero
            if(topElem1->count)
                maxHeap.push(topElem1);
            if(topElem2->count)
                maxHeap.push(topElem2);
        }

        //now there might be a possibility of one element left in the heap.
        if(maxHeap.size()==1){
            if(maxHeap.top()->count>1)
                return "";
            char ch=maxHeap.top()->data;
            maxHeap.pop();
            return ans+ch;
        }

        return ans;
    }