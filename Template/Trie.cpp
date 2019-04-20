#include<bits/stdc++.h>
using namespace std;
struct node{
    node *next[10];
    bool endmark;
    node(){
        endmark=false;
        for(int i=0;i<10;i++) next[i]=NULL;
    }
};
bool valid;
void insert(node *root, string s){
    node *cur=root;
    for(int i=0;i<s.length();i++){
        int in=s[i]-'0';
        if(cur->next[in]==NULL) cur->next[in]=new node();
        cur=cur->next[in];
        if(cur->endmark) valid=false;
    }
    cur->endmark=true;
    for(int i=0;i<10;i++)
    if(cur->next[i]!=NULL) valid=false;
}
void remove(node *root){
    for(int i=0;i<10;i++)
        if(root->next[i]!=NULL) remove(root->next[i]);
    delete(root);
}
int main(){
    int t,nt=0,n;
    string s;
    cin>>t;
    while(t--){
        cin>>n;
        valid=true;
        node *root=new node();
        for(int i=0;i<n;i++){
            cin>>s;
            insert(root,s);
        }
        printf("Case %d: ",++nt);
        if(valid) puts("YES");
        else puts("NO");
        remove(root);
    }
}
