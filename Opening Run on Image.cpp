#include<bits/stdc++.h>
using namespace std;
const int n=16,m=3;

int fit1(int pixI[m][m],int pixJ[m][m]){
	int ans=0;
    for(int i=0;i<m;i++){
    	for(int j=0;j<m;j++){
          ans+=(pixI[i][j]*pixJ[i][j]);
    	}
    }
    return ans;
}

bool isFit(int image[n][n],int pix1[m][m],int x,int y){
	int fitPixelOri=fit1(pix1,pix1);
	int ans=0;
	int macroPix[m][m];
             macroPix[0][0]=image[x-1][y-1];
             macroPix[0][1]=image[x-1][y];
             macroPix[0][2]=image[x-1][y+1];
             macroPix[1][0]=image[x][y-1];
             macroPix[1][1]=image[x][y];
             macroPix[1][2]=image[x][y+1];
             macroPix[2][0]=image[x+1][y-1];
             macroPix[2][1]=image[x+1][y];
             macroPix[2][2]=image[x+1][y+1];

             for(int i=0;i<m;i++){
             	for(int j=0;j<m;j++){
             		ans+=(macroPix[i][j]*pix1[i][j]);
             	}
             }
             if(ans==fitPixelOri)return true;
             else return false;
}

bool isFit1(int image[n+2][n+2],int pix1[m][m],int x,int y){
	int ans=0;
	int macroPix[m][m];
             macroPix[0][0]=image[x-1][y-1];
             macroPix[0][1]=image[x-1][y];
             macroPix[0][2]=image[x-1][y+1];
             macroPix[1][0]=image[x][y-1];
             macroPix[1][1]=image[x][y];
             macroPix[1][2]=image[x][y+1];
             macroPix[2][0]=image[x+1][y-1];
             macroPix[2][1]=image[x+1][y];
             macroPix[2][2]=image[x+1][y+1];

             for(int i=0;i<m;i++){
             	for(int j=0;j<m;j++){
             		ans+=(macroPix[i][j]*pix1[i][j]);
             	}
             }
             if(ans!=0)return true;
             else return false;
}

int32_t main(){
	 ios_base::sync_with_stdio(false);
 	 cin.tie(NULL); 
 	 cout.tie(NULL);
 	 #ifndef ONLINE_JUDGE 
 	 freopen("input.txt","r",stdin); 
 	 freopen("output.txt","w",stdout); 
 	 #endif
 	 auto start=clock();
     int image[n][n];
     int newImage[n][n];
     for(int i=0;i<n;i++){
     	for(int j=0;j<n;j++){
     		cin>>image[i][j];
     		newImage[i][j]=0;
     	}
     }
     int pixel[m][m];
     for(int i=0;i<m;i++){
     	for(int j=0;j<m;j++){
     		cin>>pixel[i][j];
     	}
     }
     for(int i=1;i<n-1;i++){
     	for(int j=1;j<n-1;j++){
     		if(isFit(image,pixel,i,j)){
     			newImage[i][j]=1;
     		}else{
     			newImage[i][j]=0;
     		}
     	}
     }
     //Letstry Zero Padding
     int newImage2[n+2][n+2];
     for(int i=0;i<n+2;i++){
     	for(int j=0;j<n+2;j++){
           if( j==0 ||
            i==0 ||
            i==n+1 ||
            j==n+1){
           	newImage2[i][j]=0;
           }else{
           	newImage2[i][j]=newImage[i][j];
           }
     	}
     }
     int finalImage[n+1][n+1];
     for(int i=1;i<n+1;i++){
     	for(int j=1;j<n+1;j++){
             if(isFit1(newImage2,pixel,i,j)){
               finalImage[i][j]=1;
             }else{
             	finalImage[i][j]=0;
             }
     	}
     }
     for(int i=1;i<=n;i++){
     	for(int j=1;j<=n;j++){
     		cout<<finalImage[i][j]<<' ';
     	}
     	cout<<'\n';
     }

 	 cerr<<1.0 * (clock()-start)/CLOCKS_PER_SEC<<endl;
 	 return 0;
}
