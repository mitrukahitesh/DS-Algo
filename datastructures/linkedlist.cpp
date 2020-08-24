#include <iostream>

using namespace std;

struct node
{
    int data;
    node* next;
};

void add_node(node* a){
    cout<<"Enter n to add:\n";
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        node* temp = new node;
        temp = a;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        node* temp1 = new node;
        temp->next=temp1;
        temp1->data=i;
        temp1->next=NULL;
    }
}

void print_node(node* a){
    node* temp;             //we can use (a) instead of temp as (a) in this function is the copy of the (a)
    temp = a;               //of the main function i.e. it's value is just a copied value, not the actual a
    while(temp!=NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }	
}

void insert_at_beginning(node* & a){  //& is used so that we can change the address store in (a) so that it points to
	node* temp = new node;            //the new head of the family
	temp->data = -1;
	temp->next = a;
	a = temp;
}

int main(){
    node* a;
    a=NULL;
    node* temp;
    temp = new node;
    temp->data=2;
    temp->next=NULL;
    a=temp;
    add_node(a);
    cout<<"\n";
    print_node(a);
    insert_at_beginning(a);
    cout<<"\n";
    print_node(a);
    return 0;
}