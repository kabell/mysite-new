#include<iostream>

using namespace std;

int pole[3000][3000];

int main(){

long long k,n;
int x,y;

cin>>n;

for(int i=0; i<=2000; i++){
for(int j=0; j<=2000; j++)
pole[i][j]=-1;

}

for(int i=1; i<=n; i++)
for(int j=1; j<=n; j++){
cin>>pole[i][j];
if(pole[i][j]==0){
y=i; x=j;
}
}


cin>>k;

for(long long i=0; i<k; i++)
{
int p;
cin>>p;





if(pole[y][x+1]==p){
pole[y][x]=p;
pole[y][x+1]=0;
x++;
continue;
}

if(pole[y][x-1]==p){
pole[y][x]=p;
pole[y][x-1]=0;
x--;
continue;
}


if(pole[y+1][x]==p){
pole[y][x]=p;
pole[y+1][x]=0;
y++;
continue;
}

if(pole[y-1][x]==p){
pole[y][x]=p;
pole[y-1][x]=0;
y--;
continue;
}

}

for(int i=1; i<=n; i++){
for(int j=1; j<=n; j++)
if(j<n)
cout<<pole[i][j]<<" ";
else
cout<<pole[i][j];

cout<<endl;
}





return 0;
}
