#include<iostream>
using namespace std;
#define MAXN 100001
#define K 25
int main(){
	int log[MAXN+1],a[MAXN],n,m,R,L;
	log[1] = 0;
	for (int i = 2; i <= MAXN; i++)
		log[i] = log[i/2] + 1;
	int st[MAXN][K];
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	for (int i = 0; i < n; i++)
		st[i][0] = a[i];

	for (int j = 1; j <= K; j++)
		for (int i = 0; i + (1 << j) <= n; i++)
			st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
	scanf("%d",&m);
	while(m--){
		scanf("%d%d",&L,&R);
		int j = log[R - L + 1];
		printf("%d\n",min(st[L][j], st[R - (1 << j) + 1][j]));
	}
}
