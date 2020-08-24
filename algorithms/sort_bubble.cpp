#include <iostream>
using namespace std;

int main(){
	int n=10;
	int arr[n]={10, 9, 8, 7, 6, 4, 5, 3, 2, 1};
	for(int i=0; i<n-1; i++){
		int flag=0;
		for(int j=0; j<n-i-1; j++){
			if(arr[j+1]<arr[j]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				flag=1;
			}
		}
		if(flag==0)
			break;
	}
	cout<<"Sorted in ascending order:\n";
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}