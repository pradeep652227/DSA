
    class Compare{
        public:
        bool operator()(ListNode* a,ListNode* b){
                if(a==nullptr && b==nullptr)
                    return false;
                else if(a==nullptr)
                    return false;
                else if(b==nullptr)
                    return true;
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //build a minHeap of size k
        priority_queue<ListNode*,vector<ListNode*>,Compare>minHeap(lists.begin(),lists.end());
        
        ListNode* newHead=nullptr;
        ListNode* newTail=nullptr;
        while(!minHeap.empty()){
            //1st pop the minElem
            ListNode* minElem=minHeap.top();
            //insert it in the final list
            if(newHead==nullptr){
                newHead=minElem;
                newTail=minElem;
            }
            else{
                newTail->next=minElem;
                newTail=minElem;
            }
           minHeap.pop();
            //insert next elem
            if(minElem==nullptr || minElem->next==nullptr)
               continue;
            minHeap.push(minElem->next);
        }

        return newHead;
    }