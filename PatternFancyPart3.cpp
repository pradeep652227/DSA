#include <iostream>
using namespace std;

int main() {
  int n;cin>>n;
  /*Fancy Pattern*/
 for(int i=0;i<n;i++){
   //rows
   int numOfCols{2*i+1};
   int midCol{numOfCols/2};
   int numToPrint{1};
   for(int j=0;j<numOfCols;j++){//cols
     if(j==0 || j==numOfCols-1)
      cout<<"*"; 
      else if(j>=midCol)
      cout<<numToPrint--;
      else
      cout<<numToPrint++;
   }
   cout<<endl;
 }

 int newRow=n-1;
 for(int i=newRow-1;i>=0;i--){
   //rows
   int numOfCols{2*i+1};
   int midCol{numOfCols/2};
   int numToPrint{1};
   for(int j=0;j<numOfCols;j++){
     if(j==0 || j==numOfCols-1)
      cout<<"*"; 
      else if(j>=midCol)
      cout<<numToPrint--;
      else
      cout<<numToPrint++;
   }
   cout<<endl;
 }
  
  return 0;
}