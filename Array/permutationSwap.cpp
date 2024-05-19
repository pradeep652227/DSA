#include <iostream>
#include <climits>
#include <vector>

using namespace std;
int sortWithMax_KValue(int* &arr,int n){
    int k{INT_MAX};
    for(int i=1;i<=n;i++){
        if(arr[i-1]!=i){
            int absDiff=arr[i-1]-arr[arr[i-1]-1];
            if(absDiff<0)
            absDiff*=(-1);
            k=min(k,absDiff);
            swap(arr[i-1],arr[arr[i-1]-1]);
        }
    }
    return k;
}

int main(){
    int t; cin>>t;
    while(t){
        int n;cin>>n;
        int *arr=new int[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<sortWithMax_KValue(arr,n)<<endl;
        t--;
    }
    return 0;
}