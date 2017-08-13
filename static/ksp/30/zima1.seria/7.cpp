#include <iostream>

using namespace std;

long long maxim=100000000000000000;

long long pole[1047][1047];

long long r,s;

int chod(long long min, long long temp,long long x,long long y){

if(x==r && y==s){ cout<<endl;
return 0;
};


if(pole[x+1][y]+temp>=min && pole[x+1][y]!=0 ){
cout<<"D";
chod(min,temp,x+1,y);
}
else if(pole[x+1][y]+temp<=min && pole[x][y+1]!=0){
cout<<"P";
chod(min,temp+pole[x+1][y],x,y+1);
}


else
while(true)
cout<<"l";





}









int main(){

long long q;


cin>>r>>s>>q;

for(int i=1; i<=r; i++)
for(int j=1; j<=s; j++){
int temp=0;;
cin>>temp;
if(temp==1) pole[i][j]=0;
else pole[i][j]=-1;
}

//reading


pole[r][s]=1;

for(int i=r; i>0; i--)
for(int j=s; j>0; j--){

if(pole[i][j]!=0){
if(i==r && j==s) continue;

else if(i==r) pole[i][j]=pole[i][j+1];

else if(j==s) pole[i][j]=pole[i+1][j];
else if(pole[i+1][j]+pole[i][j+1]<maxim)
pole[i][j]=pole[i+1][j]+pole[i][j+1];
else pole[i][j]=maxim;
}
}





for(int i=1; i<=q; i++){
long long temp;
cin>>temp;
if(pole[1][1]<temp){ cout<<"neexistuje"<<endl; continue;}
chod(temp, 0,1,1);











}


















}

