#include <cstdio>
#include <algorithm>
using namespace std;
struct Edge{
	int src,dest,len;
	bool operator<(const Edge& a){
		return len<a.len;
	}
};
Edge edge[200001];
int parent[200001];
int find_root(int x){
	if(parent[x]==x)
		return x;
	return parent[x]=find_root(parent[x]);
}
int main(){
	int n,m,x,y,z,ans,p_src,p_dest;
	while(scanf("%d%d",&m,&n)&&(n!=0||m!=0)){
		ans=0;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&x,&y,&z);
			edge[i].src=x;
			edge[i].dest=y;
			edge[i].len=z;
			ans+=z;
		}
		sort(edge,edge+n);
		for(int i=0;i<m;i++) parent[i]=i;
		for(int i=0;i<n;i++){
			p_src=find_root(edge[i].src);
			p_dest=find_root(edge[i].dest);
			if(p_src!=p_dest){
				parent[p_src]=parent[p_dest];
				ans-=edge[i].len;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
