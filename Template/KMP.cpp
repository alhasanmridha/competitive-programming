    #include<bits/stdc++.h>
    using namespace std;
    int F[1000001];
    string s,p;
    void build(){
        int m=p.length();
        int i=0,j=-1;
        F[0]=-1;
        while(i<m){
            while(j>=0&&p[j]!=p[i])
                j=F[j];
            i++;
            j++;
            F[i]=j;
        }
    }
    int kmp(string s,string p){
        int n=s.length(),m=p.length(),i=0,j=0,cnt=0;
        build();
        while(i<n){
            while(j>=0&&s[i]!=p[j])
                j=F[j];
            i++;
            j++;
            if(j==m){
                cnt++;
                j=F[j];
            }
        }
        return cnt;
    }
    int main(){
        int t;
        cin>>t;
        for(int nt=1;nt<=t;nt++){
            cin>>s>>p;
            cout<<"Case "<<nt<<": "<<kmp(s,p)<<"\n";
        }
        return 0;
    }

