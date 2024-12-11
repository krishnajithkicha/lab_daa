#include<iostream>
#include<climits>
using namespace std;

bool Bellman(int vert,int edg,int edgl[][3],int s){
	int dis[vert];
	int parent[vert];
	//intialize
	for(int i=0;i<vert;i++){
		dis[i]=INT_MAX;
		parent[i]=-1;
	}
	dis[s]=0;
	//relax
	for(int i=1;i<vert-1;i++){
		for(int j=0;j<edg;j++){
			int u=edgl[j][0];
			int v=edgl[j][1];
			int w=edgl[j][2];
		
		if(dis[u]!=INT_MAX && dis[u]+w<dis[v]){
			dis[v]=dis[u]+w;
			parent[v]=u;
		}
		
	}
}
	//negcyc
	for(int j=0;j<edg;j++){
			int u=edgl[j][0];
			int v=edgl[j][1];
			int w=edgl[j][2];
		if(dis[u]!=INT_MAX && dis[u]+w<dis[v]){
			return false;
		}
	}
	
	//path
	cout<<"VERTEX\t\t\t DIST\t\t\t Short"<<endl;
	for(int i=0;i<vert;i++){
		if(dis[i]==INT_MAX){
			cout<<i<<"\tINF\t\t"<<endl;	
		}
		else{
			cout<<i<<"\t\t\t"<<dis[i]<<"\t\t\t";
		}
		
		int cur=i;
		while (cur!=-1){
			cout<<cur;
			cur=parent[cur];
			if(cur!=-1) cout<<" -";
		}
		cout<<endl;
		}
	return true;
}
int main(){
	int v,e;
	cout<<"Enter vertex:";
	cin>>v;
	cout<<"Enter edge:";
	cin>>e;
	int edl[e][3];
	for(int i=0;i<e;i++){
		cin>>edl[i][0]>>edl[i][1]>>edl[i][2];
	}
	int s;
	cout<<"eNTER souc:";
	cin>>s;
	if(Bellman(v,e,edl,s)){
		cout<<"np";
	}
	else{
		cout<<"ye";
	}
	return 0;
}
