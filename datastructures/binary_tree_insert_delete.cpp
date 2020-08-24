#include <iostream>
using namespace std;

class max_heap{
private:
	int *arr;
	int last=-1;
	int capacity;
public:
	max_heap(int n):capacity(n){arr=new int[n];}
	void insert_heap(int);
	int delete_heap();
	void print_heap();
};

void max_heap::insert_heap(int x){
	if(last+1==capacity){
		cout<<"Limit reached";
		return;
	}
	arr[++last]=x;
	if((last-1)<0)
		return ;
	int i=last;
	while((i-1)>=0){
		if(arr[i]>arr[(i-1)/2]){
			int temp=arr[i];
			arr[i]=arr[(i-1)/2];
			arr[(i-1)/2]=temp;
		}
		else{
			break;
		}
		i=(i-1)/2;
	}
}

void max_heap::print_heap(){
	for(int i=0; i<=last; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}

int max_heap::delete_heap(){
	int r_val=arr[0];
	arr[0]=arr[last];
	--last;
	int i=0;
	while((2*i+1)<=last){
		if((2*i+2)>last){
			if(arr[i]<arr[2*i+1]){
				int temp=arr[i];
				arr[i]=arr[2*i+1];
				arr[2*i+1]=temp;
			}
			break;
		}
		else{
			if(arr[i]<arr[2*i+2] || arr[i]<arr[2*i+1]){
				if(arr[2*i+2]>arr[2*i+1]){
					int temp=arr[2*i+2];
					arr[2*i+2]=arr[i];
					arr[i]=temp;
					i=2*i+2;
				}
				else{
					int temp=arr[2*i+1];
					arr[2*i+1]=arr[i];
					arr[i]=temp;
					i=2*i+1;
				}
			}
			else{
				break;
			}
		}
	}
	return r_val;
}

int main(){
	max_heap heap(10);
	heap.insert_heap(1);
	heap.insert_heap(2);
	heap.insert_heap(3);
	heap.insert_heap(4);
	heap.insert_heap(5);
	heap.insert_heap(6);
	heap.insert_heap(7);
	heap.insert_heap(8);
	heap.insert_heap(9);
	heap.insert_heap(10);
	heap.print_heap();
	for(int i=0; i<10; i++)
	cout<<heap.delete_heap()<<endl;
	return 0;
}