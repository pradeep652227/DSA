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
      int numOfCols{2*row+1}, midCol{numOfCols/2}, numToPrint{row+1};
      for(int cols=0;cols<numOfCols;cols++){
        if(cols>=midCol){
          cout<<numToPrint;
          numToPrint=numToPrint-1;
        }
        else
        cout<<numToPrint++;
      }
      cout<<endl;
  }
  return 0;
}