#include <iostream>

using namespace std;

class queue{
private:
	int size=5;
	int* data=new int[5];
	int head;
	int tail;
public:
	queue(){head=-1; tail=-1;}
	void Enqueue(int x){
		if(head==-1 && tail==-1){
			head=0;
			tail=0;
			data[tail]=x;
			return ;
		}
		if((tail+1)%size==head){
			cout<<"queue is full- returned withput adding";
			return ; 
		}
		tail=(tail+1)%size;
		data[tail]=x;
	}

	void Dequeue(){
		if(head==-1 && tail==-1){
			cout<<"queue is empty";
			return ;
		}
		if(head==tail){
			head=-1;
			tail=-1;
			return ;
		}
		head=(head+1)%size;
	}
	int peek(){
		try{
			if(head!=-1)
			return data[head];
			throw -1;
		}
		catch(int error){
			cout<<"queue is empty- returned value is garbage value";
			return data[head];
		}
	}
	bool isEmpty(){
		if(head==-1 && tail==-1)
			return true;
		return false;
	}
	void print(){                  //extra function to check
		for (int i = head; ; )
		{
			cout<<data[i]<<endl;
			if(i==tail)
				break;
			i=(i+1)%size;
		}
	}
};

int main(){
	queue q;
	q.Enqueue(1);
	q.Enqueue(2);
	q.Enqueue(3);
	q.Enqueue(4);
	q.Enqueue(5);
	q.print();     //1 2 3 4 5 
	cout<<endl;
	q.Dequeue();
	q.print();     //2 3 4 5 
	cout<<endl;
	q.Enqueue(6);  
	q.print();	   //2 3 4 5 6 
	cout<<endl;
	q.Dequeue();
	q.Dequeue();
	q.print();
	cout<<endl;
	cout<<q.peek()<<endl;
	cout<<endl;
	if(!q.isEmpty()){
		q.Dequeue();
		cout<<q.peek()<<endl;
		cout<<endl;
		q.Dequeue();
		cout<<q.peek()<<endl;
		cout<<endl;
		q.Dequeue();
	}
	if(q.isEmpty())
		cout<<"queue is empty"<<endl;
	return 0;
}