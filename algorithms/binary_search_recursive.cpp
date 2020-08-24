#include <iostream>

using namespace std;

int binary_search(int *arr, int first, int last, int key){
	if(first>last)
		return -1;
	int mid=(first+last)/2;
	if(arr[mid]==key)
		return mid;
	else if(key>arr[mid])
		return binary_search(arr, mid+1, last, key);
	else
		return binary_search(arr, first, mid-1, key);
}

int main(){
	int *arr;
	int n;
	cout<<"Enter n:\n";
	cin>>n;
	arr=new int[n];
	cout<<"Enter sorted array:\n";
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	int key;
	cout<<"Enter element to be searched:\n";
	cin>>key; 
	int index=binary_search(arr, 0, n-1, key);
	cout<<index<<endl;
	return 0;
}