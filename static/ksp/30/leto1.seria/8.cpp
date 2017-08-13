#include<iostream>
#include<vector>

using namespace std;

long long gcd(long long n,long long m){
return m==0?n:gcd(m,n%m);
}

long long NMN(int k){
long long suc=2,suc1=2;
for(int i=3; i<=k; i++){
suc1=gcd(suc,i);
suc=(suc*i)/suc1;
}
return suc;
}


long long a,b,k,nmn;
vector<long long> V;


long long rataj(long long zac,long long kon){

for(int i=0; i<=nmn; i++)
V[i]=0;

for(int i=zac; i<=kon; i++)
V[i]=9876543210;
V[zac]=0;

for(int i=zac; i<kon; i++){

if(V[i+1]>V[i]+1) V[i+1]=V[i]+1;

for(int j=2; j<=k; j++){
if(i%j==0)
for(int l=1; l<j; l++)
if(V[i+l]>V[i]+1)
V[i+l]=V[i]+1;



}
/*
for(int i=0; i<=20; i++)
cout<<V[i]<<" ";
cout<<endl;
*/
}

/*
for(int i=0; i<=20; i++)
cout<<V[i]<<" ";
cout<<endl;
*/
return V[kon];
}





int main(){


cin>>a>>b>>k;

nmn=NMN(k);
V.resize(nmn+47);
//cout<<nmn<<endl;
long long perioda=rataj(0,nmn);
long long zac1=rataj(b%nmn,a%nmn);
long long zac=rataj(b%nmn,nmn);
long long kon=rataj(0,a%nmn);

/*
cout<<"perioda= "<<perioda<<endl;
cout<<"zac1= "<<zac1<<endl;
cout<<"zac= "<<zac<<endl;
cout<<"kon= "<<kon<<endl;
*/

long long sucet=kon+((long long)(a/nmn)-(long long)(b/nmn)-1)*perioda+zac;
if(a-b<1000000 && a<nmn)
sucet=rataj(b,a);


if(a==b) cout<<"0"<<endl;
else
cout<<sucet<<endl;






}
