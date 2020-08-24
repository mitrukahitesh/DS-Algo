#include <iostream>

using namespace std;

class stack{
private:
	int data;
	stack* next;
	stack* top;
public:
	stack(){top = NULL; next=NULL;}
	void push(int d){
		stack* temp = new stack;
		temp->data = d;
		temp->next=NULL;
		if(top!=NULL){
			temp->next = top;
		}
		top=temp;
	}
	void print(){                 //this operation is not present in stack
		stack* temp = top;
		while(temp!=NULL){
			cout<<temp->data<<endl;
			temp=temp->next;
		} 
	}
	int peek(){
		return top->data;
	}
	void pop(){
		if(top==NULL){
			cout<<"Stack is empty\n";
			return ;
		}
		stack* temp = top;
		top = top->next;
		delete temp;
	}
	bool isEmpty(){
		if(top==NULL){
			return true; 
		}
		else{
			return false;
		}
	}
};


int main(){
	stack s;
	if(s.isEmpty()){
		cout<<"Stack is empty\n";
	}
	s.push(1);
	s.push(2);
	s.push(3);
	cout<<"Push\n";
	s.print();
	if(s.isEmpty()){
		cout<<"Stack is empty\n";
	}
	cout<<"Peek: "<<s.peek()<<endl;
	cout<<"Pop\n";
	s.pop();
	cout<<"Peek: "<<s.peek()<<endl;
	return 0;
}