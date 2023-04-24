#include <iostream>
using namespace std;
/*Numerical Pyramid Pattern */
int main() {
  int n;
  cin>>n;

  for(int row=0;row<n;row++){
    for(int spaces=0;spaces<(n-1-row);spaces++){
      cout<<" ";
    }
      int numOfCols{2*row+1};
      for(int cols=0;cols<numOfCols;cols++){
        if(row==0 || row==n-1)
        cout<<"*";
        else if (cols==0 || cols==numOfCols-1)
        cout<<"*";
        else
        cout<<" ";
      }
      cout<<endl;
  }
  return 0;
}