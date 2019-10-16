#include <iostream>
#include <algorithm>
using namespace std;
int a[]={0,1,2,3,4,5,6};
bool is_ok(int x1,int y1,int x2,int y2){
	if(abs(x1-x2)==abs(y1-y2))
		return false;
	return true;
}
int main(){
	int x,y,test;
	bool fst=true;
	cin>>test;
	for(int i=1;i<=test;i++){
		cin>>x>>y;
		int it=0;
		x-=1,y-=1;
		int v[100][8];
		do{
			bool flag=true;
			for(int i=0;i<7;i++){
				int x1,y1;
				x1=(a[i]<x)?a[i]:a[i]+1;
				y1=(i<y)?i:i+1;
				if(!is_ok(x,y,x1,y1)){
					flag=false;
					break;
				}
			}
			if(flag){
				for(int i=0;i<6;i++){
					for(int j=i+1;j<7;j++){
						int x1,y1,x2,y2;
						x1=(a[i]<x)?a[i]:a[i]+1;
						y1=(i<y)?i:i+1;
						x2=(a[j]<x)?a[j]:a[j]+1;
						y2=(j<y)?j:j+1;
						if(!is_ok(x1,y1,x2,y2)){
							flag=false;
							break;
						}
					}
					if(!flag)
						break;
				}
			}
			if(flag){
				v[it][y]=x;
				for(int i=0;i<7;i++){
					if(i>=y) v[it][i+1]=(a[i]<x)?a[i]:a[i]+1;
					else v[it][i]=(a[i]<x)?a[i]:a[i]+1;
				}
				it++;
			}	
		}while(next_permutation(a,a+7));
		if(!fst) cout<<"\n";
		fst=false;
		cout << "SOLN       COLUMN\n";
		cout << " #      1 2 3 4 5 6 7 8\n\n";

		for ( int i = 0; i < it; i++ ) {
			printf ("%2d      ", i+1);
			printf ("%d", v[i][0]+1);
			for ( int j = 1; j < 8; j++ )
				printf (" %d", v [i] [j]+1);
			printf ("\n");
		}
	}
	return 0;
}
