#include <iostream>

using namespace std;

void leftRotateArray(int arr[], int n);
void printArray(int arr[],int n);

int main(int argc, char **argv)
{
	int arr[]{1,2,3,4,5};
	int n=sizeof(arr)/sizeof(int);
	cout<<"Before left-rotating "; printArray(arr,n);
	leftRotateArray(arr,n);
	cout<<endl;
	cout<<"After left-rotating "; printArray(arr,n);
	return 0;
}
void leftRotateArray(int arr[], int n){
	int firstElem=arr[0];
//	int i{0};
//	while(i<n){
//		arr[i]=arr[i+1];
//		i++;
//	}
	
	arr[n-1]=firstElem;
	return ;
}

void printArray(int arr[], int n){
	int i{0};
	while(i<n){
		cout<<arr[i]<<" ";
		i++;
	}
	return;
}
