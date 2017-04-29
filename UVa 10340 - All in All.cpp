#include <iostream>
using namespace std;
string s,t;
bool is_sub(int l1,int l2){
    if(l1==0) return true;
    if(l2==0) return false;
    if(s[l1-1]==t[l2-1]) return is_sub(l1-1,l2-1);
    return is_sub(l1,l2-1); 
}
int main(){
    int l1,l2;
    while(cin>>s>>t){
        l1=s.length();
        l2=t.length();
        cout<<(is_sub(l1,l2)?"Yes\n":"No\n");
    }
    return 0;
}
