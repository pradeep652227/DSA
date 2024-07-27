#include <bits/stdc++.h>
using namespace std;

bool checkDistance(vector<int>& stalls, int k, int targetDist) {
    int prevStall = stalls[0];
    k -= 1; // placed one cow
    
    for (int i = 1; i < stalls.size(); i++) {
        if (stalls[i] - prevStall >= targetDist) {
            prevStall = stalls[i];
            k--;
            if (k == 0)
                return true;
        }
    }
    
    return false;
}

int aggressiveCows(vector<int> &stalls, int k) {
    int n = stalls.size();
    // 2<=k<=n
  sort(stalls.begin(),stalls.end());
        if(k==2)
            return stalls[n-1]-stalls[0];
        
        int min_dist=1,max_dist=stalls[n-1]-stalls[0];
        int ans(-1);
        int &l=min_dist,&r=max_dist;
        while(min_dist<=max_dist){
            int mid=min_dist+(max_dist-min_dist)/2;
            if(checkDistance(stalls,k,mid)){
                ans=mid; 
                //find the next possible greater value
                l=mid+1;
            }
              else 
              //you won't find feasible solution on the right side
              r=mid-1;
        }
}