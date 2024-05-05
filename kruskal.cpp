#include<iostream>
#include<algorithm>
using namespace std;
const int MAX=100;
int parent[MAX];
int find(int i){
	while(parent[i]!=i)
	i=parent[i];
	return i;
}
void union_ij(int i,int j){
	int a=find(i);
	int b=find(j);
	parent[a]=b;
}
void kruskal(int cost[MAX][MAX],int n){
	int mincost=0;
	for(int i=0;i<n;i++){
		parent[i]=i;
	}
	int edge=0;
	while(edge<n-1){
		int min=999,a=-1,b=-1;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(find(i)!=find(j)&&cost[i][j]<min){
					min=cost[i][j];
					a=i;b=j;
				}
			}
		}
		union_ij(a,b);
		cout<<"edge (" <<a<<" , "<<b<<") cost: "<<min<<endl;
		mincost+=min;
		++edge;
	}
	cout<<"minimum cost spanning tree: "<<mincost<<endl;
}

int main(){
	int n;
	cout<<"enter number of verices: ";
	cin>>n;
	int cost[MAX][MAX];
	cout<<"enter matrix(print 999 if no edge or infinity): \n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>cost[i][j];
		}
	}
	kruskal(cost,n);
	return 0;
}


