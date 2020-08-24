#include <iostream>
using namespace std;

//create a array with parent of all members
void makeset(int* parent, int n){
	for(int i=0; i<n; i++)
		parent[i] = i;
}

//check whether both elements lie in same set
//node in same set end up with same root
//worst case O(n)
int find(char* elements, int* parent, int n, char c){
	int i=-1;
	for(int k=0; k<n; k++){
		if(elements[k]==c)
			i=k;
	}
	if(i==-1)
		return -1;
	while(parent[i]!=i){
		i=parent[i];
	}
	return i;
}

//perform union operation when elements are in different sets
//O(1)
void Union(char* elements, int* parent, int n, char c1, char c2){
	int i, j;
	if(( (i=find(elements, parent, n, c1)) != (j=find(elements, parent, n, c2)) )){
		if(i>=0 && j>=0)  //i j cannot be negative
		parent[i]=j;
	}
}

int main(){
	int n=10;
	char elements[n]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	int parent[n];
	makeset(parent, n);
	Union(elements, parent, n, 'a', 'b');
	Union(elements, parent, n, 'c', 'd');
	Union(elements, parent, n, 'e', 'f');
	Union(elements, parent, n, 'g', 'h');
	Union(elements, parent, n, 'i', 'j');
	Union(elements, parent, n, 'b', 'c');
	Union(elements, parent, n, 'f', 'i');
	for(int i=0; i<n; i++){
		cout<<parent[i]<<" ";
	}
	return 0;
}