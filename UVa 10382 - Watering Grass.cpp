#include<bits/stdc++.h>
using namespace std;
double l,w;
double sq(double a){
  return a*a;
}
struct cord{
  double l,r;
  bool operator<(cord o){
    return (l==o.l)?(r>o.r):(l<o.l);
  }
  cord(){
    
  }
  cord(double x,double d){
    if(d>w/2){
      l=x-sqrt(sq(d)-sq(w/2));
      r=x+sqrt(sq(d)-sq(w/2));
    }
    else{
      l=x;
      r=x;
    }
  }
};
int main(){
  int n;
  double x,d;
  cord c[10000];
  while(scanf("%d%lf%lf",&n,&l,&w)==3){
    bool is_found=false;
    double r_max=0;
    for(int i=0;i<n;i++){
      scanf("%lf%lf",&x,&d);
      c[i]=cord(x,d);
      r_max=max(r_max,c[i].r);
    }
    
    sort(c,c+n);
    if(r_max<l){
      cout<<"-1\n";//<<" is the answer because l value is "<<l<<"\n";
      continue;
    }
    int i,cnt=0;
    double r=0,lt=0;
    for(i=0;i<n;){
      cnt++;
      if(c[i].l>r){
        cout<<-1<<"\n";
        break;
      }
      while(c[i].l<=lt&&i<n){
        r=max(r,c[i].r);
        i++;
      }
      lt=r;
      if(r>=l){
        cout<<cnt<<"\n";
        break;
      }
    }
  }
}
