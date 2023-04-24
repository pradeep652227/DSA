#include <iostream>
using namespace std;

int main() {
  int n; cin>>n;

  for(int i=0;i<n;i++){//rows
    for(int j=0;j<(n-i);j++){//cols
      cout<<"*";
    }
    for(int k=0;k<(2*i+1);k++){
      //spaces
      cout<<" ";
    }
    for(int j=0;j<(n-i);j++){
      //cols
      cout<<"*";
    }

    cout<<endl;
  }

  for(int i=0;i<n;i++){
    //rows
    for(int j=0;j<=i;j++)//cols
    cout<<"*";
    for(int k=0;k<2*(n-1-i)+1;k++)//spaces
    cout<<" ";
    for(int j=0;j<=i;j++)//cols
    cout<<"*";

    cout<<endl;
  }
  return 0;
}