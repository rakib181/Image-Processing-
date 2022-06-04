#include<bits/stdc++.h>
using namespace std;

double table[8][8],pixel1[4][4],pixel2[4][4],macroPix[4][4],gx[6][6],gy[6][6],M[6][6],Angle[6][6];


double letsTry1(int x,int y){
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
      ans+=(pixel1[i][j]*macroPix[i][j]);
   }
}
 return ans;
}
double letsTry2(int x,int y){
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
      ans+=(pixel2[i][j]*macroPix[i][j]);
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
            cin>>pixel1[i][j];
         }
    }
     for(int i=0;i<3;i++){
         for(int j=0;j<3;j++){
            cin>>pixel2[i][j];
         }
    }
     for(int i=1;i<=5;i++){
      for(int j=1;j<=5;j++){
        gx[i][j]=letsTry1(i,j);
      }
     }
     for(int i=1;i<=5;i++){
      for(int j=1;j<=5;j++){
        gy[i][j]=letsTry2(i,j);
      }
     }
     for(int i=1;i<=5;i++){
      for(int j=1;j<=5;j++){
        M[i][j]=sqrt((gx[i][j]*gx[i][j])+(gy[i][j]*gy[i][j]));
      }
     }
     for(int i=1;i<=5;i++){
      for(int j=1;j<=5;j++){
        double x=(gy[i][j]/gx[i][j]);
        double result=atan(x);
        Angle[i][j]=(result*180)/3.1415;
      }
     }
     for(int i=1;i<=5;i++){
      for(int j=1;j<=5;j++){
        cout << M[i][j] << ' ';
      }
      cout << '\n';
     }
     cout << '\n';
      for(int i=1;i<=5;i++){
      for(int j=1;j<=5;j++){
        cout << Angle[i][j] << ' ';
      }
      cout << '\n';
     }
    cerr<< 1.0 * (clock()-st)/CLOCKS_PER_SEC<<'\n';
   return 0;
}
