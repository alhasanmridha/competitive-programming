#include <bits/stdc++.h>
using namespace std;
int n,m,grid[1000][1000],dist[1000][1000];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool visited[1000][1000];
int inf=1000000000;
bool is_valid(int r,int c){
	if(r>=n||c>=m||r<0||c<0||visited[r][c])
		return false;
	return true;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		memset(visited,false,sizeof(visited));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				scanf("%d",&grid[i][j]);
				dist[i][j]=inf;
			}
		}
		priority_queue<pair<int,pair<int,int> > ,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > >q;
		dist[0][0]=grid[0][0];
		q.push({dist[0][0],{0,0}});
		while(!q.empty()){
			pair<int,pair<int,int> > node=q.top();q.pop();
			int r=node.second.first;
			int c=node.second.second;
			visited[r][c]=true;
			for(int i=0;i<4;i++){
				int nr=r+dx[i];
				int nc=c+dy[i];
				if(is_valid(nr,nc) && dist[nr][nc]>dist[r][c]+grid[nr][nc]){
					dist[nr][nc]=dist[r][c]+grid[nr][nc];
					q.push({dist[nr][nc],{nr,nc}});
				}
			}
		}
		cout<<dist[n-1][m-1]<<"\n";
	}
}
