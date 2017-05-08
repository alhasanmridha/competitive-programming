#include <bits/stdc++.h>
using namespace std;
int inf=1000000000;
int main(){
	int N,n,s,t,m,w,n1,n2;
	cin>>N;
	for(int i=0;i<N;i++){
		vector<int> dist;
		vector<pair<int,int> >adj[20001];
		cin>>n>>m>>s>>t;
		while(m--){
			cin>>n1>>n2>>w;
			adj[n1].push_back(pair<int,int>(w,n2));
			adj[n2].push_back(pair<int,int>(w,n1));
		}
		dist.assign(n,inf);
		dist[s]=0;
		priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
		q.push(pair<int,int>(0,s));
		while(!q.empty()){
			pair<int,int> cur=q.top();
			q.pop();
			int d=cur.first;
			int u=cur.second;
			for(int i=0;i<adj[u].size();i++){
				int alt=dist[u]+adj[u][i].first;
				if(alt<dist[adj[u][i].second]){
					dist[adj[u][i].second]=alt;
					q.push(pair<int,int>(alt,adj[u][i].second));
				}
			}
		}
		cout<<"Case #"<<i+1<<": ";
		if(dist[t]==inf)
			puts("unreachable");
		else
			cout<<dist[t]<<"\n";
	}
}
