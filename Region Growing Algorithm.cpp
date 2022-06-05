#include<bits/stdc++.h>
using namespace std;
int n;
int pixel[105][105],vis[105][105];
int dx[8]={-1,1,0,0,-1,-1,1,1};
int dy[8]={0,0,-1,1,-1,1,-1,1};

void dfs(int x,int y){
  if(x<0 || x>=n)return;
  if(y<0 || y>=n)return;

  if(!vis[x][y]){
    vis[x][y]=1;
    for(int i=0;i<8;i++){
      int _x=x+dx[i];int _y=y+dy[i];
      if(!vis[_x][_y] && abs(pixel[x][y]-pixel[_x][_y])==50){
        dfs(_x,_y);
      }
    }
  }
}
int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt","r",stdin); 
    freopen("output.txt","w",stdout); 
    #endif
    auto start=clock();
    cin >> n;
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cin>>pixel[i][j];
      }
    }
    int x,y;
    cin >> x >> y;
    dfs(x,y);
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        cout << vis[i][j] << ' ';
      }
      cout << '\n';
    }
    
    cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
    return 0;
}
