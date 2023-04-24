#include <iostream>
using namespace std;

int main() {
  int n; cin>>n;

  for(int i=0;i<n;i++) // rows
  {
    for(int j=0;j<n-1-i;j++)// spaces
    cout<<" ";
    int numOfCols=2*i+1;
    for(int k=0;k<numOfCols;k++)// stars
    {
      if(k==0 || k==numOfCols-1)
      cout<<"*";
      else
      cout<<" ";
    }
    cout<<endl;
  }
  /*Inverted Hollow*/
  for(int i=n;i>0;i--) // rows
  {
    for(int j=0;j<n-i;j++)// spaces
    cout<<" ";
    int numOfCols=2*i-1;
    for(int k=0;k<numOfCols;k++)// stars
    {
      if(k==0 || k==numOfCols-1)
      cout<<"*";
      else
      cout<<" ";
    }
    cout<<endl;
  }
   return 0;
}