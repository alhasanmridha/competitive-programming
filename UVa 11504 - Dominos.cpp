//Problem Link
//https://uva.onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=&problem=2499
#include <iostream>
#include <vector>
#include <cstdio>
#include <stack>
#include <fstream>
using namespace std;
vector<int> *v;
stack<int>top_sort;
bool *vis;
void dfs(int indx){
	vis[indx]=true;
	for(int i=0;i<v[indx].size();i++){
		if(!vis[v[indx][i]])
			dfs(v[indx][i]);
	}
	top_sort.push(indx);
}
int main(){
	// ifstream cin("input.txt");
	// ofstream cout("output.txt");
	int t,n,m,a,b,count,super;
	//scanf("%d",&t);
	cin>>t;
	while(t--){
		count=0;
		cin>>n>>m;
		//scanf("%d%d",&n,&m);
		v=new vector<int>[n];
		vis=new bool[n];
		for(int i=0;i<n;i++)
			vis[i]=false;
		for(int i=0;i<m;i++){
			cin>>a>>b;
			//scanf("%d%d",&a,&b);
			v[a-1].push_back(b-1);
		}
		for(int i=0;i<n;i++){
			if(!vis[i])
				dfs(i);
		}
		for(int i=0;i<n;i++)
			vis[i]=false;
		while(!top_sort.empty()){
			super=top_sort.top();
			if(!vis[super]){
				dfs(super);
				count++;
			}
			top_sort.pop();
		}
		cout<<count<<"\n";
	}
	return 0;
}
