#include <iostream>
using namespace std;

int arr_maxElem(int *arr,int& n);

int main() {
  int arr[]{1,20,3,6,5};
  int n{sizeof(arr)/sizeof(int)};

  cout<<"Maximum element is "<<arr_maxElem(arr,n);
  return 0;
}

int arr_maxElem(int arr[],int& n){// 0 se n-1 tak max layega

  if(n==0)
  return arr[0];

  int prevMax= arr_maxElem(arr,--n);// 0 se n-2 tak max layega
  if(arr[n-1]>prevMax) // 0 se n-1 and 0 se n-2 , remaining n-1 ko check
                        // karlo taki overall maximum aajaye.
    prevMax=arr[n-1];
  return prevMax;
}