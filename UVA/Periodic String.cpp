#include<iostream>
#include<string>
using namespace std;
int kmp[1000000];
int main(){
	string s;
	int t;
	cin>>t;
	while(t--){
		cin>>s;
		int n=s.length(),j;
		for(int i=1;i<n;i++){
			j=kmp[i-1];
			while(j>0 and s[j]!=s[i])
				j=kmp[j-1];
			if(s[i]==s[j])
				j++;
			kmp[i]=j;
		}
		if(n%(n-kmp[n-1])==0)
			cout<<n-kmp[n-1]<<"\n";
		else
			cout<<n<<"\n";
		if(t>0)
		cout<<"\n";
	}
}
