#include <iostream>
#include <vector>
using namespace std;

void printSpiral(vector<vector<int>>& arr);
int main() {
  vector<vector<int>>arr{
    {1,2,3,4},
    {5,6,7,8},
    {9,10,11,12},
    {13,14,15,16}
  };

  printSpiral(arr);
  return 0;
}

void printSpiral(vector<vector<int>>& arr){
  int n=arr.size();
  int m=arr[0].size();
  int row=0,col=0;
  //row==col
  while((row+1)!=n-1){
    int i=row,j=col;

    while(j<m-1-row){//left to right horizontal
      cout<<arr[i][j]<<" ";
      j++;
    }
    cout<<"  ";
    while(i<n-1-row){
      cout<<arr[i][j]<<" ";
      i++;
    }
    cout<<"  ";
    //row==col
    while(j>col){
      cout<<arr[i][j]<<" ";
      j--;
    }
    cout<<"  ";
    while(i>row){
      cout<<arr[i][j]<<" ";
      i--;
    }
    cout<<"  ";
    
    row++;col++;
  }

}