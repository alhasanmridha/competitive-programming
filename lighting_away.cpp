#include <iostream>
#include <vector>
#include <cstdio>
#include <stack>
using namespace std;
vector<int> *v;
stack<int>top_sort;
bool vis[10001];
void dfs(int indx){
	vis[indx]=true;
	for(int i=0;i<v[indx].size();i++){
		if(!vis[v[indx][i]])
			dfs(v[indx][i]);
	}
	top_sort.push(indx);
}
int main(){
	int t,n,m,a,b,count,super;
	scanf("%d",&t);
	for(int it=1;it<=t;it++){
		count=0;
		scanf("%d%d",&n,&m);
		v=new vector<int>[n];
		for(int i=0;i<n;i++)
			vis[i]=false;
		for(int i=0;i<m;i++){
			scanf("%d%d",&a,&b);
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
		cout<<"Case "<<it<<": "<<count<<"\n";
	}
}