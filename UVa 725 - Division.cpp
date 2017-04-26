#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
using namespace std;
bool check(int a,int b){
    vector<int>v;
    if(a<10000&&b<10000)
        return false;
    if(a<10000)
        v.push_back(0);
    while(a){
        v.push_back(a%10);
        a/=10;
    }
    while(b){
        v.push_back(b%10);
        b/=10;
    }
    set<int>s(v.begin(),v.end());
    if(s.size()<10)
        return false;
    return true;
}
int main(){
    int n,d,cnt;
    cin>>n;
    vector<int>v;
    cnt=0;
    for(d=1234;d*n<=98765;d++){
        if(check(d,d*n)){
            cnt++;
            v.push_back(d);
        }
    }
    if(!cnt){
        printf ("There are no solutions for %d.\n", n);
    }
    else{
        for(int i=0;i<cnt;i++){
            printf ("%d / ", v[i]*n);
            if(v[i]<10000)
                printf("0");
            printf("%d = %d\n",v[i],n);
        }
    }
    while(cin>>n){
        if(n==0)
            break;
        printf("\n");
        vector<int>v;
        cnt=0;
        for(d=1234;d*n<=98765;d++){
            if(check(d,d*n)){
                cnt++;
                v.push_back(d);
            }
        }
        if(!cnt){
            printf ("There are no solutions for %d.\n", n);
        }
        else{
            for(int i=0;i<cnt;i++){
                printf ("%d / ", v[i]*n);
                if(v[i]<10000)
                    printf("0");
                printf("%d = %d\n",v[i],n);
            }
        }
    }
    return 0;
}
