#include <iostream>
using namespace std;

int main() {
  int n;cin>>n;

  for(int i=0;i<n;i++){
    //rows
    for(int j=0;j<=i;j++){
      //cols
      cout<<i+1;
      if(j!=i)
      cout<<"*";
    }
    cout<<endl;
  }
  for(int i=0;i<n;i++){
    //rows
    for(int j=0;j<n-i;j++){
      //cols
      cout<<n-i;
      if(j!=(n-i-1))
      cout<<"*";
    }
    cout<<endl;
  }
  return 0;
}