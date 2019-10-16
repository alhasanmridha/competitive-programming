//Problem Link:
//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1246
#include <iostream>
#include <vector>
#include <stack>
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
	int n,m,a,b;
	while(true){
		cin>>n>>m;
		if(n==0&&m==0)
			return 0;
		v=new vector<int>[n];
		vis=new bool[n];
		for(int i=0;i<n;i++)
			vis[i]=false;
		for(int i=0;i<m;i++){
			cin>>a>>b;
			v[a-1].push_back(b-1);
		}
		for(int i=0;i<n;i++){
			if(!vis[i])
				dfs(i);
		}
		for(int i=0;i<n;i++)
			vis[i]=false;
		while(!top_sort.empty()){
			cout<<top_sort.top()+1<<" ";
			top_sort.pop();
		}
		cout<<"\n";
	}
	return 0;
}
