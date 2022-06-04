#include<bits/stdc++.h>
using namespace std;

double table[8][8],pixel[4][4],macroPix[4][4];

double letsTry(int x,int y){
  double ans=0;
             macroPix[0][0]=table[x-1][y-1];
             macroPix[0][1]=table[x-1][y];
             macroPix[0][2]=table[x-1][y+1];
             macroPix[1][0]=table[x][y-1];
             macroPix[1][1]=table[x][y];
             macroPix[1][2]=table[x][y+1];
             macroPix[2][0]=table[x+1][y-1];
             macroPix[2][1]=table[x+1][y];
             macroPix[2][2]=table[x+1][y+1];
for(int i=0;i<3;i++){
   for(int j=0;j<3;j++){
      ans+=(pixel[i][j]*macroPix[i][j]);
   }
}
 return ans;
}

int32_t main(){
   ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    auto st=clock();
    for(int i=0;i<7;i++){
      for(int j=0;j<7;j++){
         cin>>table[i][j];
      }
    }
    for(int i=0;i<3;i++){
         for(int j=0;j<3;j++){
            cin>>pixel[i][j];
         }
    }
    for(int i=1;i<=5;i++){
      for(int j=1;j<=5;j++){
        cout<<letsTry(i,j)<<' ';
      }
      cout<<'\n';
    }
    cerr<< 1.0 * (clock()-st)/CLOCKS_PER_SEC<<'\n';
   return 0;
}
