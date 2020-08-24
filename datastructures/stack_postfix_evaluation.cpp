#include <iostream>
#include <sstream>
#include <string.h>

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

int evaluate_postfix(string expr){
	stringstream ss(expr);
	stack s;
	char sign;
	while(1){
		if(ss.peek()=='+' || ss.peek()=='-' || ss.peek()=='*' || ss.peek()=='/'){
			int var2 = s.peek();
			s.pop();
			int var1 = s.peek();
			s.pop();
			ss>>sign;
			switch (sign){
				case '+':
					s.push(var1+var2);
					break;
				case '-':
					s.push(var1-var2);
					break;
				case '*':
					s.push(var1*var2);
					break;
				case '/':
					s.push(var1/var2);
					break;
			}
		}
		else if(ss.peek()>=48 && ss.peek()<=57){
			int x;
			ss>>x;
			s.push(x);
		}
		else{
			if(ss.peek()!=' ')
			break;
			else
			ss.get();
		}
	}
	int ans = s.peek();
	return ans;
}

int main(){
	string expr = "2 3 + 100 *";
	int ans = evaluate_postfix(expr);
	cout<<endl<<expr<<" = "<<ans<<endl;
	return 0;
}