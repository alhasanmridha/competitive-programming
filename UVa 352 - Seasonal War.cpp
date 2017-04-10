#include <bits/stdc++.h>
using namespace std;
int dr[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
string s[26];
int n;
bool is_valid(int r,int c){
  if(r<n&&r>=0&&c<n&&c>=0) return true;
  return false;
}
void dfs(int r,int c){
  s[r][c]='0';
  for(int i=0;i<8;i++)
    if(is_valid(r+dr[i],c+dc[i]))
      if(s[r+dr[i]][c+dc[i]]=='1')
        dfs(r+dr[i],c+dc[i]);
}
 int main(){
  int it=1;
  while(cin>>n){
    for(int i=0;i<n;i++){
      cin>>s[i];
    }
    int count=0;
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
      if(s[i][j]=='1'){
      count++;
      dfs(i,j);
    }
    cout<<"Image number "<<it<<" contains "<<count<<" war eagles.\n";
    it++;
  }
  return 0;
}
