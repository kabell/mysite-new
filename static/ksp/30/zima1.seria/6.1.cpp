#include<iostream>
#include<algorithm>
#include<cstdio>

using namespace std;

long long pole[100047];

bool compare (const long long &a, const long long &b)
{
return abs(a)>abs(b);
}
int main(){



cout<<"ok"<<endl;

long long k,l,minus,max=0;

//cin>>k>>l;
scanf("%lld%lld",&k,&l);
for(int i=1; i<=k; i++)
//cin>>pole[i];
scanf("%lld",&pole[i]);
scanf("%lld",&minus);

for(int i=1; i<=k-l+1; i++)
{
long long pole1[l];
for(int j=0; j<l; j++)
pole1[j]=pole[j+i];

sort(pole1,pole1+l,compare);

long long pocet=minus;
for(int j=0; j<l; j++)
{
if(pocet==0) break;
if(pole1[j]<0){ pole1[j]*=-1; pocet--;}
}
long long sum=0;
for(int j=0; j<l; j++)
{
sum+=pole1[j];
if(j%1000==0) cout<<j<<endl;
}

if(abs(sum)>max) max=abs(sum);
//pre minus


for(int j=0; j<l; j++)
pole1[j]=pole[j+i];

sort(pole1,pole1+l,compare);

pocet=minus;
for(int j=0; j<l; j++)
{
if(pocet==0) break;
if(pole1[j]>0){ pole1[j]*=-1; pocet--;}
}
sum=0;
for(int j=0; j<l; j++)
{
sum+=pole1[j];
if(i%1000==0) cout<<i<<endl;
}

if(abs(sum)>max) max=abs(sum);

}



cout<<max<<endl;



}
