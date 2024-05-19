#include <iostream>
using namespace std;
/*Numerical Pyramid Pattern */
int main() {
  int n;
  cin>>n;

  for(int row=0;row<n;row++){
    for(int spaces=0;spaces<n-1-row;spaces++){
      cout<<" ";
    }
    for(int cols=0;cols<row+1;cols++){
      cout<<"* ";
    }
  cout<<endl;
  }
  return 0;
}