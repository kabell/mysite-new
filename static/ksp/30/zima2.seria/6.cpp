#include<iostream>

using namespace std;

int pole[2][2047];
int naj[2][2047];
int c[2047];
int d[2047];
int r,s,x,y;

int main(){
cin>>r>>s>>x>>y;

for(int i=1; i<=r; i++)
for(int j=1; j<=s; j++){
char t;
cin>>t;
if(t=='#') pole[0][j]++;
}

for(int i=1; i<=s; i++)
pole[1][i]=r-pole[0][i];

int suc=0;
for(int i=1; i<=s; i++)
suc+=pole[0][i];

naj[0][0]=0;
naj[1][0]=0;
for(int i=1; i<=s; i++){
naj[0][i]=10000000;
naj[1][i]=10000000;
}
int t=0;

for(int i=1; i<=s; i++){

for(int j=i; j<i+x-1; j++)
c[i]+=pole[0][j];

d[i]=(x-1)*r-c[i];
}

//for(int i=1; i<=s; i++)
//cout<<c[i]<<" ";
//cout<<endl;

for(int i=0; i<s; i++){
//cout<<"i="<<i<<endl;
//cout<<"prvy"<<endl;
if(naj[0][i]<10000000){

int sum=naj[0][i];
//cout<<sum<<" k "<<endl;;
sum+=c[i+1];
//cout<<sum<<" l "<<endl;;
for(int j=x; j<=y; j++){
sum+=pole[0][j+i];
//cout<<"i+j="<<i+j<<endl;
//cout<<sum<<endl;
if(sum<naj[1][i+j]) naj[1][i+j]=sum;

}
}
//cout<<endl;
//for(int w=1; w<=s; w++)
//cout<<naj[0][w]<<" ";
//cout<<endl;
//for(int w=1; w<=s; w++)
//cout<<naj[1][w]<<" ";
//cout<<endl;
//cout<<"druhzy"<<endl;
if(naj[1][i]==10000000) continue;

int sum=naj[1][i];
//cout<<sum<<" k "<<endl;;
sum+=d[i+1];
//cout<<sum<<" l "<<endl;;
for(int j=x; j<=y; j++){
sum+=pole[1][j+i];
//cout<<"i+j="<<i+j<<endl;
//cout<<sum<<endl;
if(sum<naj[0][i+j]) naj[0][i+j]=sum;

}
//cout<<endl;
//for(int w=1; w<=s; w++)
//cout<<naj[0][w]<<" ";
//cout<<endl;
//for(int w=1; w<=s; w++)
//cout<<naj[1][w]<<" ";
//cout<<endl;
}

/*
for(int i=1; i<=s; i++)
cout<<pole[0][i]<<" ";
cout<<endl;
for(int i=1; i<=s; i++)
cout<<pole[1][i]<<" ";
cout<<endl;
for(int i=1; i<=s; i++)
cout<<naj[0][i]<<" ";
cout<<endl;
for(int i=1; i<=s; i++)
cout<<naj[1][i]<<" ";
cout<<endl;
for(int i=1; i<=s; i++)
cout<<c[i]<<" ";
cout<<endl;
for(int i=1; i<=s; i++)
cout<<d[i]<<" ";
cout<<endl;
*/

cout<<min(naj[0][s],naj[1][s])<<endl;


}
