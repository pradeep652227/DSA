#include <iostream>
using namespace std;

int main() {
  int n;cin>>n;
 /*Fancy Pattern #1 */
  for(int i=0;i<n;i++){
    //rows
    for(int j=0;j<(2*n-2-i);j++)//stars
    cout<<"*";
    for(int k=0;k<=i;k++){
      //cols
      cout<<i+1;
      if(k!=i)
      cout<<"*";
    }

    for(int j=0;j<(2*n-2-i);j++)//stars
    cout<<"*";
    cout<<endl;

  }
  return 0;
}