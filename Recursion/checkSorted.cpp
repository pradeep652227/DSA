#include <iostream>
#include <vector>
using namespace std;
/*Check Sorted*/
bool checkSorted(vector<int>& arr,int& n);
int main() {
  vector<int>arr{1,2,3,6,5};
  int n=arr.size();
  cout<<"Is array Sorted?? "<<checkSorted(arr,n)<<endl;

  return 0;
}

bool checkSorted(vector<int>& arr,int& n){

  if(n==1)// when only one element
  return true;

  if(arr[n-1]<arr[n-2])
  return false;
   
   return checkSorted(arr,--n);
}