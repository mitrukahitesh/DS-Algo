#include <iostream>
using namespace std;

void heapify(int *arr, int n){
	for(int i=n-1; i>=0; i--){
		int root=i;
		while(root<n){
		    int l=2*root+1;
		    int r=2*root+2;
		    if(l>=n)
		    	break;
			if(l<n && r>=n){
				if(arr[l]>arr[root]){
					int temp=arr[l];
					arr[l]=arr[root];
					arr[root]=temp;
				}
				break;
			}
			if(arr[l]>arr[root] || arr[r]>arr[root]){
				if(arr[r]>arr[l]){
					int temp=arr[r];
					arr[r]=arr[root];
					arr[root]=temp;
					root=r;
				}
				else{
					int temp=arr[l];
					arr[l]=arr[root];
					arr[root]=temp;
					root=l;
				}
			}
			else{
				break;
			}
		}
	}
}

void heap_sort(int *arr, int n){
	heapify(arr, n);
	cout<<"Heapified...\n";
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	int last=n-1;
	for(int i=0; i<n; i++){
		int temp=arr[0];
		arr[0]=arr[last];
		arr[last]=temp;
		--last;
		int root=0;
		while(root<=last){
			int l=2*root+1;
			int r=2*root+2;
			if(l>last){
				break;
			}
			if(l<=last && r>last){
				if(arr[l]>arr[root]){
					int temp=arr[l];
					arr[l]=arr[root];
					arr[root]=temp;
				}
				break;
			}
			if(arr[l]>arr[root] || arr[r]>arr[root]){
				if(arr[l]>arr[r]){
					int temp=arr[l];
					arr[l]=arr[root];
					arr[root]=temp;
					root=l;
				}
				else{
					int temp=arr[r];
					arr[r]=arr[root];
					arr[root]=temp;
					root=r;
				}
			}
			else{
				break;
			}
		}
	}
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	heap_sort(arr, n);   //max heap, ascending order
	cout<<"Sorted...\n";
	for(int i=0; i<n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}