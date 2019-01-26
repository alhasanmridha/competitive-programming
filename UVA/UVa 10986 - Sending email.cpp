#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>ii;
typedef vector<ii>vii;
int T,test,n,m,s,t,u,v,w,tu;
int main(){
	cin>>test;
	for(T=1;T<=test;T++){
		cout<<"Case #"<<T<<": ";
		cin>>n>>m>>s>>t;
		vii adj[n];
		vector<int>dist(n,INT_MAX);
		for(int i=0;i<m;i++){
			cin>>u>>v>>w;
			adj[u].push_back(ii(v,w));
			adj[v].push_back(ii(u,w));
		}
		priority_queue<ii,vii,greater<ii> >Q;
		Q.push(ii(0,s));
		dist[s]=0;
		bool vis[20001];
		for(int i=0;i<n;i++) vis[i]=false;
			while(!Q.empty()){
				ii top=Q.top();
				Q.pop();
				int d=top.first,tu=top.second;
				vis[tu]=true;
				for(int i=0;i<adj[tu].size();i++){
					int tv=adj[tu][i].first;
					int length=adj[tu][i].second;
					int alt=length+dist[tu];
					if(alt<dist[tv]){
						dist[tv]=alt;
						Q.push(ii(alt,tv));
					}
				}
			}
			if(!vis[t]) cout<<"unreachable\n";
			else cout<<dist[t]<<"\n";
		}
	}
