#include <iostream>
using namespace std;

//create a array with parent of all members
void makeset(int* parent, int n){
	for(int i=0; i<n; i++)
		parent[i] = i;
}

//check whether both elements lie in same set
bool find(char* elements, int* parent, int n, char c1, char c2){
	int i=-1, j=-1;
	for(int k=0; k<n; k++){
		if(elements[k]==c1)
			i=k;
		if(elements[k]==c2)
			j=k;
	}
	if(i==-1 || j==-1)
		return false;
	if(parent[i]==parent[j])
		return false;
	return true;     //not in same set
}

//perform union operation when elements are in different sets
void Union(char* elements, int* parent, int n, char c1, char c2){
	if(find(elements, parent, n, c1, c2)){
		int i, j;
		for(int k=0; k<n; k++){
			if(elements[k]==c1)
				i=k;
			if(elements[k]==c2)
				j=k;
		}
		i=parent[i];
		j=parent[j];
		if(j>i){
			for(int k=0; k<n; k++){
				if(parent[k]==i)
					parent[k]=j;
			}
		}
		else{
			for(int k=0; k<n; k++){
				if(parent[k]==j)
					parent[k]=i;
			}
		}
	}
}

int main(){
	int n=10;
	char elements[n]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	int parent[n];
	makeset(parent, n);
	Union(elements, parent, n, 'a', 'b');
	Union(elements, parent, n, 'c', 'd');
	Union(elements, parent, n, 'e', 'x');
	Union(elements, parent, n, 'g', 'h');
	Union(elements, parent, n, 'i', 'j');
	Union(elements, parent, n, 'b', 'c');
	Union(elements, parent, n, 'f', 'i');
	for(int i=0; i<n; i++){
		cout<<parent[i]<<" ";
	}
	return 0;
}