#include <iostream>
using namespace std;
  /*Printing array using recursion*/

void print_arr(int *arr,int n);
void print_arr(int *arr,int n,int idx);

int main() {
  int arr[]{1,2,3,4,5};
  int n=sizeof(arr)/sizeof(int);
  // print_arr(arr,n);
  int idx=0;
  print_arr(arr,n,idx);
  return 0;
}
/*
void print_arr(int arr[],int n){
  if(n==0){
    return;
  }
  print_arr(arr,n-1);
  cout<<arr[n-1]<<" ";

}
*/

void print_arr(int arr[],int n,int idx){
  if(idx>=n){
    return ;
  }

  cout<<arr[idx]<<" ";
  print_arr(arr,n,++idx);
}