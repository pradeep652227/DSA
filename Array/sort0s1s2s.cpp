#include <iostream>
#include <vector>
using namespace std;
/*Sort 0s, 1s, and 2s*/
//s-0 e-2 and m-1 ke liye
//0 to s-1 toh 0s and e+1 to n-1 hain 2s
//Main kya hai- s se e tak 1s/0s/2s inko karna padega sahi jagah place

void printArr(vector<int>& nums);
void sortColors(vector<int>& nums);

int main() {
  vector<int> nums;
  int n;cout<<"Enter the size of array ";cin>>n;cout<<endl;
  for(int i=0;i<n;i++){
    int num;cin>>num;
    nums.push_back(num);
  }
  cout<<"Before sorting, array is- "; 
  printArr(nums);
  sortColors(nums);
  cout<<"After sorting, array is- ";
  printArr(nums);

  return 0;
}
void printArr(vector<int>& nums){
  for(auto& i:nums)
  cout<<i<<" ";
  cout<<endl;
}
 void sortColors(vector<int>& nums) {
        int n=nums.size();
        int start=0,end=n-1; // for 0 and 2 respectively
        int& s=start, &e=end;
        int mid=(s+e)/2; //for 1
        int& m=mid;
        // 00... 11.. 22 
if(n>1){
            mid=0;
        while(s<=e && mid<=n-1 && mid<=end){
            if(nums[start]==0)
            start++;
            else if (nums[start]==2)
            swap(nums[end--],nums[start]);
            else{//nums[start]==1
                if(mid<s)
                    mid=s+1;// 0 to s-1= Os and s to mid-1= 1s
                else {
                    if(nums[mid]==0)
                    swap(nums[start++],nums[mid++]);
                    else if(nums[mid]==2)
                    swap(nums[end--],nums[mid]);
                    else
                    mid++;
                }
            }
        }
        /* while(s<=e && (mid>=0 && mid<=n-1)){
                if(nums[start]==0)
                    start++;
                else if(nums[start]==2)
                    swap(nums[end--],nums[start]);
                else {// nums[start]->1
                    if(nums[mid]==0 && mid>s)// dekh 0 se s-1 = Os s se m-1 tak = 1s toh 
                    // agar s aage aaya m se, matlab s++ karke, or m piche raha matlab m pe 0 he tha
                    swap(nums[start++],nums[mid++]);
                    else if(nums[mid]==2){
                        if(e>mid)
                         swap(nums[end--],nums[mid]);
                      else  //end ke right mein 2 hai or mid ke left mein 1 par start to mid-1 ke ////beech mein 0s/2s bhi hai
                        start++;// start ke left mein toh 0 hai
                    }
                   
                    else 
                    mid++;
                }

                if(mid==s && mid==e)
                    break;
         }*/

         /*   while(s<=e && mid>=s && mid<=e){
                if(nums[start]>nums[end])
                swap(nums[start],nums[end]);

                else if(nums[start]==nums[end]){
                    if(nums[start]==0)
                        s++;
                    else if(nums[start]==1)
                        swap(nums[start],nums[mid++]);
                    else if(nums[start]==2)
                        end--;
                }
                    if(nums[start]==0)
                        start++;
                    else if(nums[start]==1){
                        if(nums[mid]==0)
                            swap(nums[start++],nums[mid++]);
                        else if(nums[mid]==2)
                        swap(nums[end--],nums[mid]);
                        else
                            mid++;
                    }
                }*/
        } 
     /*   while(s<=e && mid>=s && mid<=e){
          int start=nums.at(s);
          if(start==2)
          swap(nums.at(s),nums.at(e--));

          else if(start==1){
              if(nums.at(mid)==1){
                if(s==mid)// when 0 to s/mid are zero then ++ both
                s++;
                mid++;
              }
               
            else if(nums.at(mid)==2)
                mid--;
            else //when mid-> 0
                swap(nums.at(s),nums.at(mid++));
          }
          else s++;
        }*/
    }