//Problem link:
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1301
#include <iostream>
#include <cstdio>
using namespace std;
int valid(int x){
	if(x<0) return 0;
	if(x>1024) return 1024;
	return x;
}
int tc,d,n,x,y,r,m,g[1025][1025];
int main(){
	cin>>tc;
	while(tc--){
		scanf("%d%d",&d,&n);
		for(int i=0;i<1025;i++)
			for(int j=0;j<1025;j++)
				g[i][j]=0;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&x,&y,&r);
			for(int i=valid(x-d);i<=valid(x+d);i++)
				for(int j=valid(y-d);j<=valid(y+d);j++)
					g[i][j]+=r;
		}
		m=0;
		for(int i=0;i<1025;i++){
			for(int j=0;j<1025;j++){
				if(g[i][j]>m){
					m=g[i][j];
					x=i;
					y=j;
				}
			}
		}
		printf("%d %d %d\n",x,y,m);
	}
	return 0;
}
